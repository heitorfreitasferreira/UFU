typedef struct no *Fila;

typedef struct
{
  long int matricula;
  float nota;
  int faltas;
} Aluno;

Fila cria_fila();
int fila_vazia(Fila *);
int push(Fila *, Aluno);
int shift(Fila *, Aluno *);
