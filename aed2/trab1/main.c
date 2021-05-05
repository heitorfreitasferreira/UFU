#include <stdio.h>
#include "hash.h"
/*
    Integrantes:
      Heitor Freitas Ferreira - 11921BCC026
      Luis Gustavo Seiji Tateish - 11921BCC034
  */
// Quantidade de alunos a serem lidos: 2287
// Método de leitura dos dados: arquivo txt
// Cada linha é do modelo [matricula nome n1 n2 n3] com espaço separando cada linha

int main(int argc, char const *argv[])
{
  Aluno al1;
  Hash *hash = criaHash(SIZE, sizeof(Aluno));
  FILE *p;
  // char arq[100];
  int loop = 1;
  if (!(p = fopen("alunos.txt", "r+")))
  {
    printf("Erro! Impossivel abrir o arquivo!\n");
    return 0;
  }
  while (fscanf(p, "%d %s %d %d %d", &al1.matricula, al1.nome, &al1.n1, &al1.n2, &al1.n3) != EOF)
  {
    if (insereHash(hash, al1.matricula, &al1))
    {
    }
    else
    {
      printf("Falha ao inserir, tente novamente mais tarde\n");
    }
  }
  while (loop)
  {
    int escolha;
    printf("1-Inserir novo aluno\n2-Buscar aluno\n3-Sair\n:");
    scanf("%d", &escolha);
    switch (escolha)
    {
    case 1:
      printf("Digite a matricula do aluno novo: ");
      scanf("%d", &al1.matricula);

      printf("Digite o nome do aluno novo: ");
      setbuf(stdin, NULL);
      scanf("%[^\n]s", al1.nome); // mudei aqui
      setbuf(stdin, NULL);
      printf("Digite a nota da nota da primeira prova: ");
      scanf("%d", &al1.n1);
      printf("Digite a nota da nota da segunda prova: ");
      scanf("%d", &al1.n2);
      printf("Digite a nota da nota da terceira prova: ");
      scanf("%d", &al1.n3);
      if (insereHash(hash, al1.matricula, &al1))
      {
        printf("Aluno inserido com sucesso\n");
      }
      else
      {
        printf("Falha ao inserir, tente novamente mais tarde\n");
      }
      break;
    case 2:
      printf("\nInsira o numero de matricula: ");
      int matricula;
      scanf("%d", &matricula);
      if (buscaHash(hash, matricula, &al1))
      {
        printf("Nome: %s\n", al1.nome);
        printf("Numero de matricula: %d\n", al1.matricula);
        printf("Nota da prova 1: %d\n", al1.n1);
        printf("Nota da prova 2: %d\n", al1.n2);
        printf("Nota da prova 3: %d\n", al1.n3);
      }
      else
      {
        printf("Aluno não encontrado\n");
      }
      break;
    case 3:
      loop = 0;
      break;
    default:
      printf("Digite apenas 1,2 ou 3");
      break;
    }
  }
  liberaHash(hash);
  fclose(p);
  return 0;
}