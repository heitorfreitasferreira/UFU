#include <stdio.h>
#include "hash.h"
/*
  Integrantes:
    Heitor Freitas Ferreira - 11921BCC026
    Luis Gustavo Seiji Tateish - 11921BCC___
    Terceiro otário - _____BCC___
*/
// Quantidade de alunos a serem lidos: 2287
// Método de leitura dos dados: arquivo txt
// Cada linha é do modelo [matricula nome n1 n2 n3] com espaço separando cada linha
int main(int argc, char const *argv[])
{
  Hash *hash = criaHash(SIZE,);
  FILE *p;
  char arq[100];
  int loop = 1;
  if (!(p = fopen(arq,"r+"))){                           
    printf("Erro! Impossivel abrir o arquivo!\n");
    exit(1);
  }
  while (!feof(p)){
    int matricula,n1,n2,n3;
    char nome[30];
    fscanf(p,"%d",&matricula);
    fscanf(p,"%s",nome);
    fscanf(p,"%c%c%c",&n1,&n2,&n3);
    insereHash();
  }
  while (loop)
  {
    int escolha;
    printf("1-Inserir novo aluno\n2-Buscar aluno\n3-Sair");
    scanf("%c",&escolha);
    switch (escolha)
    {
    case 1:
      insereHash();
      break;
    case 2:
      buscaHash(,int matricula,);
      frea
    case 3:
      break;
    default:
      printf("Digite apenas 1,2 ou 3");
      break;
    }
  }
  
  fclose(p);
  return 0;
}
