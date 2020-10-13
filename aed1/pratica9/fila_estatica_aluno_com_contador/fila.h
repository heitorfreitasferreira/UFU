#define max 20
typedef struct lista *Fila;
typedef struct
{
  int matricula, faltas;
  char nome[50];
  float media;
} Aluno;
Fila cria_fila();
int fila_vazia(Fila);
int fila_cheia(Fila);
int push(Fila, Aluno);
int shift(Fila, Aluno *);
int get_size(Fila);