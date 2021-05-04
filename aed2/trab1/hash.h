#define SIZE 19

//Mudar aqui sua estrutura de dado

typedef struct aluno
{
  char nome[30];
  int matricula, n1, n2, n3;
} Aluno;

typedef struct data
{
  int key;
  void *value;
} Data;
typedef struct hash Hash;

Hash *criaHash(int TABLE_SIZE, int TAMANHO_TIPO);
void liberaHash(Hash *ha);
int insereHash(Hash *ha, int key, void *dados);
int buscaHash(Hash *ha, int key, void *dados);
