#include "lista.h"
#include <stdlib.h>
struct no
{
  float info;
  struct no *prox;
  struct no *ant;
};

int lista_vazia(Lista lst)
{
  return (!lst);
}
int insere_elem(Lista *lst, float elem, int pos)
{
  Lista N = (Lista)malloc(sizeof(struct no));
  if (N == NULL)
    return 0;

  N->info = elem;
  if (lista_vazia(*lst))
  {
    N->ant = NULL;
    N->prox = *lst;
    if (!lista_vazia(*lst))
      (*lst)->ant = N;
    *lst = N;
    return 1;
  }
  Lista aux = *lst;

  while (aux->prox != NULL && pos--)
    aux = aux->prox;
  if (aux->prox == NULL && aux->info < elem)
  {
    N->prox = NULL;
    N->ant = aux;
    aux->prox = N;
    return 1;
  }
  N->prox = aux;
  N->ant = aux->ant;
  aux->ant = N;
  N->ant->prox = N;
  return 1;
}
int get_pos_elem(Lista *lst, float elem, int *pos)
{
  if (lista_vazia(*lst))
    return 0;
  Lista aux = *lst;
  *pos = 1;
  while (aux->prox || aux->info == elem)
  {
    aux = aux->prox;
    (*pos)++;
  }
  return 1;
}