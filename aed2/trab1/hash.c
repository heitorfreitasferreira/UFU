#include "hash.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define bin 0x7FFFFFFF
struct hash
{
  int qnt, TABLE_SIZE, TYPE_SIZE;
  Data **itens;
};
int linear_polling(int pos, int i, int TABLE_SIZE) { return ((pos + i) && bin) % TABLE_SIZE; }

int quadratic_polling(int pos, int i, int TABLE_SIZE)
{
  pos = pos + 2 * i + 5 * i * i;
  return (pos & bin) % TABLE_SIZE;
}
//Dependendo do tipo de hash que você for usar tem que alterar ali, essa estará usando o metodo da multiplicação, sempre usar outro método do que foi utilizado para gerar H1
int double_hash(int H1, int key, int i, int TABLE_SIZE)
{
  int H2 = hash_fn_mult(key, TABLE_SIZE - 1) + 1;
  return ((H1 + i * H2) && bin) % TABLE_SIZE;
}
int hash_fn_div(int key, int TABLE_SIZE)
{
  return (key & 0x7777777 % TABLE_SIZE);
}

int hash_fn_mult(int key, int TABLE_SIZE)
{
  float A = 0.6180339887 /*const 0<A<1 */, val = key * A;
  val = val - (int)val;
  return (int)(TABLE_SIZE * val);
}
int hash_fn_fold(int key, int TABLE_SIZE)
{
  int n_bits = 10;
  int part1 = key >> n_bits;
  int part2 = key & (TABLE_SIZE - 1);
  return (part1 ^ part2);
}
int hash_fn_str(char *str)
{
  int i, value = 7, size = strlen(str);
  for (size_t i = 0; i < size; i++)
    value = 31 * value + (int)str[i];
  return value;
}
// Hash* ha = create(int number)
Hash *criaHash(int TABLE_SIZE, int TAMANHO_TIPO)
{
  Hash *ha = (Hash *)malloc(sizeof(Hash));
  if (ha)
  {
    int i;
    ha->TABLE_SIZE = TABLE_SIZE;
    ha->TYPE_SIZE = TAMANHO_TIPO;
    ha->itens = (Data **)malloc(TABLE_SIZE * sizeof(Data *));
    if (!ha->itens)
    {
      free(ha);
      return NULL;
    }
    ha->qnt = 0;
    for (size_t i = 0; i < ha->TABLE_SIZE; i++)
      ha->itens[i] = NULL;
  }
  return ha;
}
void resizeHashTable(Hash **antiga)
{
  Hash *newTable = criaHash((*antiga)->TABLE_SIZE * 2, (*antiga)->TYPE_SIZE);
  for (size_t i = 0; i < (*antiga)->TABLE_SIZE; i++)
  {
    if ((*antiga)->itens[i]) //EXISTE UM ITEM NESSA POSIÇÃO
    {
      // aqui é feita a inserção do item não nulo, fazer alteração para usar a versão do trabalho
      insereHash(newTable, (*antiga)->itens[i]);
    }
  }
  liberaHash(*antiga);
}

// // IMPLEMENTAÇÃO MAIS PERFORMÁTICA POREM INSUPORTÁVEL
// int resizeHashTable(Hash *antigo)
// {
//   int newSize = antigo->TABLE_SIZE * 2;
//   Data **NewVet = (Data **)malloc(newSize * sizeof(Data *));
//   if (!NewVet)
//   {
//     free(NewVet);
//     return 0;
//   }
//   for (size_t i = 0; i < newSize; i++)
//     NewVet[i] = NULL;
//   for (size_t i = 0; i < antigo->TABLE_SIZE; i++)
//   {
//     if (antigo->itens[i])
//     {
//       int pos = hash_fn_div(antigo->itens[i]->matricula /*chave*/, newSize), newPos;
//       for (size_t j = 0; j < newSize; j++)
//       {
//         newPos = linear_polling(pos, j, newSize);
//         if (!NewVet[newPos])
//           NewVet[newPos] = antigo->itens[i];
//       }
//       //libera o item que já foi reinserido
//       free(antigo->itens[i]);
//     }
//   }
//   antigo->itens = NewVet;
//   antigo->TABLE_SIZE = newSize;
//   return 1;
// }

//freeHash(Hash* ha)
void liberaHash(Hash *ha)
{
  if (ha)
  {
    int i;
    for (size_t i = 0; i < ha->TABLE_SIZE; i++)
    {
      if (ha->itens[i])
        free(ha->itens[i]);
    }
    free(ha->itens);
    free(ha);
  }
}
int insert_nc(Hash *ha, Data al)
{
  if (!ha || ha->qnt == ha->TABLE_SIZE)
    return 0;
  int key = al.matricula, pos = hash_fn_div(key, ha->TABLE_SIZE);
  Data *new;
  new = (Data *)malloc(sizeof(Data));
  if (!new)
    return 0;
  *new = al;
  ha->itens[pos] = new;
  ha->qnt++;
  return 1;
}

//int x = search_wc(Hash *ha, int key, Data &result)
int search_nc(Hash *ha, int key, Data *al)
{
  if (!ha)
    return 0;
  int pos = hash_fn_div(key, ha->TABLE_SIZE);
  if (ha->itens[pos] == NULL)
    return 0;
  *al = *(ha->itens[pos]);
  return 1;
}
// int x = insert(Hash* ha, Data inserted_data)
int insereHash(Hash *ha, Data al)
{
  if (!ha || ha->qnt == ha->TABLE_SIZE)
    return 0;
  int key = al.matricula;                             // pegar a chave do dado
  int newPos, pos = hash_fn_div(key, ha->TABLE_SIZE); // mudar para o metodo da sua escolha
  for (size_t i = 0; i < ha->TABLE_SIZE; i++)
  {
    newPos = linear_polling(pos, i, ha->TABLE_SIZE); // mudar para o metodo de sondagem desejado
    if (!ha->itens[newPos])
    {
      Data *new;
      new = (Data *)malloc(sizeof(Data));
      if (!new)
        return 0;
      *new = al;
      ha->itens[newPos] = new;
      ha->qnt++;
      if (ha->qnt > ha->qnt * 0.75)
        resizeHashTable(&ha); // criar outra tabela
    }
  }
}

int buscaHash(Hash *ha, int key, Data *al)
{
  if (!ha)
    return 0;
  int i, newPos, pos = hash_fn_div(key, ha->TABLE_SIZE); // mudar para o metodo da sua escolha
  for (size_t i = 0; i < ha->TABLE_SIZE; i++)
  {
    newPos = linear_polling(pos, i, ha->TABLE_SIZE); // mudar para o metodo de sondagem desejado
    if (!ha->itens[newPos])
      return 0;
    if (ha->itens[newPos]->matricula == key)
    {
      *al = *(ha->itens[newPos]);
      return 1;
    }
  }
  return 0;
}