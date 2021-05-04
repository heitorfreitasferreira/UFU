#include "hash.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#define bin 0x7FFFFFFF
struct hash
{
  int qnt, TABLE_SIZE, TYPE_SIZE;
  Data **itens;
};
int linear_polling(int pos, int i, int TABLE_SIZE) { return ((pos + i) && bin) % TABLE_SIZE; }
int hash_fn_div(int key, int TABLE_SIZE) { return (key & 0x7777777 % TABLE_SIZE); }

// Hash* ha = create(int number)
Hash *criaHash(int TABLE_SIZE, int TAMANHO_TIPO)
{
  Hash *ha = (Hash *)malloc(sizeof(Hash));
  if (ha)
  {
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
      insereHash(newTable, (*antiga)->itens[i]->key, (*antiga)->itens[i]->value);
    }
  }
  *antiga = newTable;
}

//freeHash(Hash* ha)
void liberaHash(Hash *ha)
{
  if (ha)
  {
    for (size_t i = 0; i < ha->TABLE_SIZE; i++)
    {
      if (ha->itens[i])
        free(ha->itens[i]);
    }
    free(ha->itens);
    free(ha);
  }
}
// int x = insert(Hash* ha, Data inserted_data)
int insereHash(Hash *ha, int key, void *dados)
{
  if (!ha || ha->qnt == ha->TABLE_SIZE)
    return 0;
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
      new->key = key;
      new->value = malloc(ha->TYPE_SIZE);
      memcpy(new->value, dados, ha->TYPE_SIZE);
      ha->itens[newPos] = new;
      ha->qnt++;
      if (ha->qnt > ha->TABLE_SIZE * 0.75)
      {
        resizeHashTable(&ha); // criar outra tabela}
      }
      return 1;
    }
  }
  return 0;
}

int buscaHash(Hash *ha, int key, void *dados)
{
  if (!ha)
    return 0;
  int newPos, pos = hash_fn_div(key, ha->TABLE_SIZE); // mudar para o metodo da sua escolha
  for (size_t i = 0; i < ha->TABLE_SIZE; i++)
  {
    newPos = linear_polling(pos, i, ha->TABLE_SIZE); // mudar para o metodo de sondagem desejado
    if (!ha->itens[newPos])
      return 0;
    if (ha->itens[newPos]->key == key)
    {
      memcpy(dados, ha->itens[newPos]->value, ha->TYPE_SIZE);
      return 1;
    }
  }
  return 0;
}