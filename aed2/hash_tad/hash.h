/*
  * Tabela Hash
  * Função de hash: método da divisão
  * Função de re-hash: endereçamento aberto -> sondagem linear
  * Para mudança futura:
    * Funções de re-hash disponíveis:
      * Sondagem linear: linear_polling()
       * Sondagem quadrática: quadratic_polling()
       * Duplo hash: double_hash()
    * Funções de hash disponíveis:
      * Método da divisão: hash_fn_div()
      * Método da multiplicação: hash_fn_mult()
      * Método da dobra: hash_fn_fold()
      * Método de string: hash_fn_str() -> Usar para chaves do tipo *char
*/

#define SIZE 20

//Mudar aqui sua estrutura de dado
struct data
{
  int key; //chave
  int value;
};
typedef struct hash Hash;
typedef struct data Data;

Hash *create(int TABLE_SIZE);
void freeHash(Hash *ha);
int insert(Hash *ha, Data al);
int search(Hash *ha, int key, Data *al);