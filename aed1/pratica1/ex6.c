#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
  int matricula, nota;
  char nome[50];
} Alunos;

Alunos *lerAlunos(char *qntAluno)
{
  int qntAlunos = atoi(qntAluno);
  Alunos *var;
  var = (Alunos *)malloc(qntAlunos * sizeof(Alunos));
  if (var == NULL)
  {
    printf("Erro na alocacao!!");
    exit(1);
  }
  int i;
  for (i = 0; i < qntAlunos; i++)
  {
    if (i != 0)
      printf("\n");
    printf("Numero de matricula: ");
    scanf("%d", &var[i].matricula);
    printf("Nome do aluno: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]s", var[i].nome);
    printf("Nota final: ");
    scanf("%d", &var[i].nota);
  }
  return var;
}

void gravarAlunos(Alunos *alunos, char *nome, char *qntAluno)
{
  strcat(nome, ".txt");
  int qntAlunos = atoi(qntAluno);
  FILE *arquivo;
  arquivo = fopen(nome, "a");
  if (arquivo == NULL)
  {
    printf("\nErro no arquivo");
    return 0;
  }
  fprintf(arquivo, "ALUNOS:\n");
  for (size_t i = 0; i < qntAlunos; i++)
  {

    fprintf(arquivo, "\nMATRICULA: ");
    fprintf(arquivo, alunos[i].matricula);
    fprintf(arquivo, "\nNOME: ");
    fprintf(arquivo, alunos[i].nome);
    fprintf(arquivo, "\nNOTA FINAL: ");
    fprintf(arquivo, alunos[i].nota);
    fprintf(arquivo, "\n");
  }
  fclose(arquivo);
  free(alunos);
}

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Quantidade de argumentos errado!");
    return 0;
  }
  Alunos *alunos = lerAlunos(argv[2]);
  gravarAlunos(alunos, argv[1], argv[2]);
  return 0;
}