#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char nome[30];
  double media;
  int faltas;
} Aluno;

void selectionSort(Aluno aluno[], int tam)
{
  for (int i = 0; i < tam; i++)
  {
    int menorIndex = i;
    for (int j = i + 1; j < tam; j++)
    {
      if (aluno[j].media < aluno[menorIndex].media)
      {
        menorIndex = j;
      }
    }
    int aux = aluno[i].media;
    aluno[i].media = aluno[menorIndex].media;
    aluno[menorIndex].media = aux;
  }
}

void ler_array_struct(Aluno *alunos, int qnt)
{
  for (size_t i = 0; i < qnt; i++)
  {
    printf("Nome do aluno %d: ", i + 1);

    scanf("%s", alunos[i].nome);
    printf("Media do aluno %d: ", i + 1);
    scanf("%lf", &alunos[i].media);
    printf("Faltas do aluno %d: ", i + 1);
    scanf("%d", &alunos[i].faltas);
  }
}
void print_array_struct(Aluno *alunos, int qnt)
{
  for (size_t i = 0; i < qnt; i++)
  {
    printf("Nome do aluno %d: %s\n", i + 1, alunos[i].nome);
    printf("Media do aluno %d: %lf\n", i + 1, alunos[i].media);
    printf("Faltas do aluno %d: %d\n", i + 1, alunos[i].faltas);
  }
}

int main(int argc, char const *argv[])
{
  int qnt;
  Aluno *alunos;
  scanf("%d", &qnt);
  alunos = (Aluno *)malloc(qnt * sizeof(Aluno));
  if (!alunos)
    return 1;
  ler_array_struct(alunos, qnt);
  printf("\n\n");
  selectionSort(alunos, qnt);
  print_array_struct(alunos, qnt);
  return 0;
}
