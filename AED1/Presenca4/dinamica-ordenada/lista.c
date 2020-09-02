#include "lista.h"
#include <stdlib.h>
struct no
{
  int info;
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

int insere_ord(Lista *list, char elem)
{
  Lista N = (Lista)malloc(sizeof(struct no));
  if (N == NULL)
    return 0;
  N->caractere = elem;
  if (lista_vazia(*list) || elem <= (*list)->caractere)
  {
    N->prox = *list;
    *list = N;
    return 1;
  }
  Lista aux = *list;
  while (aux->prox != NULL && aux->prox->caractere < elem)
    aux = aux->prox;
  N->prox = aux->prox;
  aux->prox = N;
  return 1;
}

int remove_ord(Lista *lst, int elem)
{
  if (lista_vazia(lst) || elem < (*lst)->info)
    return 1;

  Lista aux = *lst;
  if (elem == (*lst)->info)
  {
    *lst = aux->prox;
    free(aux);
    return 1;
  }
  else
  {
    while (aux->prox != NULL && aux->prox->info < elem)
      aux = aux->prox;
    if (aux->prox == NULL || aux->prox->info > elem) //fim da lista ou prox elemento é maior já e não achou
      return 0;
    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 1;
  }
}

int obtem_posicao(Lista lst, int indice, char *carac)
{
  if (lista_vazia(lst) || indice < 0)
    return 0;
  while (lst != NULL && indice--)
    lst = lst->prox;
  if (lst == NULL)
    return 0;
  *carac = lst->info;
  return 1;
}

int limpa_lista(Lista *list)
{
  Lista aux = *list, aux2;
  while (aux != NULL)
  {
    aux2 = aux->prox;
    free(aux);
    aux = aux2;
  }
  *list = NULL;
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