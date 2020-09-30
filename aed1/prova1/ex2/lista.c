#include <stdlib.h>
#include <string.h>
#include "lista.h"
#define max 1000

struct lista
{
  Aluno no[max];
  int end;
};
Lista cria_lista()
{
  Lista lst;
  lst = (Lista)malloc(sizeof(struct lista));
  if (lst)
    lst->end = 0;
  return lst;
}
int remove_menor(Lista lst, Aluno a)
{
  if (lst == NULL || lst->end == 0)
    return 0;
  float menor = lst->no[0].media;
  int menorIndex = 0;
  for (size_t i = 1; i < lst->end; i++)
  {
    if (lst->no[i].media < menor)
    {
      menor = lst->no[i].media;
      menorIndex = i;
    }
  }
  if (menorIndex == lst->end || lst->no[menorIndex].media != menor)
    return 0;
  a.conceito = lst->no[menorIndex].conceito;
  a.matricula = lst->no[menorIndex].matricula;
  a.media = lst->no[menorIndex].media;
  strcpy(a.nome, lst->no[menorIndex].nome);
  // a.nome = lst->no[menorIndex].nome;
  for (size_t i = menorIndex; i < lst->end; i++)
    lst->no[i - 1] = lst->no[i];
  lst->end--;
  return 1;
}