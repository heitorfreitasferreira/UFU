#define SIZE 20

//Mudar aqui sua estrutura de dado
typedef struct data
{
  int matricula; //chave
  char nome[30];
  int n1, n2, n3;
} Data;
typedef struct hash Hash;

Hash *criaHash(int TABLE_SIZE, int TAMANHO_TIPO);
void liberaHash(Hash *ha);
int insereHash(Hash *ha, void *dados);
int buscaHash(Hash *ha, int key, void *dados);