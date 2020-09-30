struct alunos
{
  long int matricula;
  char nome[10];
  float media;
  char conceito;
};
typedef struct alunos Aluno;
typedef struct lista *Lista;
Lista cria_lista();
int remove_menor(Lista, Aluno);
