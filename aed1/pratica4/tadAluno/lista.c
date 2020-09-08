#include "lista.h"
#include <stdlib.h>
#include <string.h>
struct Aluno
{
  unsigned int matricula;
  char nome[20];
  float media;
  int faltas;
};

struct no
{
  struct Aluno info;
  struct no *prox;
};
Lista cria_lista()
{
  return NULL;
}
int lista_vazia(Lista lst)
{
  return (!lst);
}
int insere_elem(Lista *lst, unsigned int matricula, char *nome, float media, int faltas)
{
  Lista N = (Lista)malloc(sizeof(struct no));
  if (!N || strlen(nome) > 20)
    return 0;
  N->info.faltas = faltas;
  N->info.media = media;
  N->info.matricula = matricula;
  strcpy(N->info.nome, nome);

  N->prox = *lst;
  *lst = N;
  return 1;
}
// int remove_elem(Lista *lst, char elem)
// {
//   if (lista_vazia(*lst))
//     return 1;
//   Lista aux = *lst;
//   if (elem == (*lst)->info)
//   {
//     *lst = aux->prox;
//     free(aux);
//     return 1;
//   }
//   else
//   {

//     aux = aux->prox;
//     if (aux->prox == NULL) //fim da lista
//       return 0;
//     Lista aux2 = aux->prox;
//     aux->prox = aux2->prox;
//     free(aux2);
//     return 1;
//   }
// }
int remove_elem(Lista *lst, unsigned int matricula)
{
  //se a lista estiver vazia nao ha como remover
  if (lista_vazia(*lst))
    return 0;
  //ponteiro para o primeiro no
  Lista aux = *lst;
  //remove o elemento se este estiver no inicio da lista
  if (matricula == ((*lst)->info.matricula))
  {
    *lst = aux->prox;
    free(aux);
    return 1;
  }
  //percorrendo lista
  while (aux->prox != NULL && aux->prox->info.matricula != matricula)
    aux = aux->prox; // avanca na lista
  //verifica se o elemento nao esta na lista
  if (aux->prox == NULL)
    return 0;
  //remove no da lista
  Lista aux2 = aux->prox; //aponta o no a ser removido
  aux->prox = aux2->prox; //retira no da lista
  free(aux2);             // libera memoria alocada;
  return 1;
}

int obtem_posicao(Lista lst, int indice, unsigned int *matricula, char *nome, float *media, int *faltas)
{
  if (lista_vazia(lst) || indice < 0)
    return 0;
  while (lst != NULL && indice--)
    lst = lst->prox;
  if (lst == NULL)
    return 0;
  strcpy(nome, lst->info.nome);
  *matricula = lst->info.matricula;
  *media = lst->info.media;
  *faltas = lst->info.faltas;
  return 1;
}

int limpa_lista(Lista *lst)
{
  if (lista_vazia(*lst))
    return 0;
  Lista aux = *lst;
  Lista aux2;
  while (aux != NULL)
  {
    aux2 = aux->prox;
    free(aux);
    aux = aux2;
  }
  *lst = NULL;
  return 1;
}
int obtem_tamanho(Lista *lst)
{
  if (lista_vazia(*lst))
    return 0;
  Lista aux = *lst;
  int i = 0;
  while (aux->prox != NULL)
  {
    aux = aux->prox;
    i++;
  }
  return i + 1;
}