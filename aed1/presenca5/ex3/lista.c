#include "lista.h"
#include <stdlib.h>
struct lista
{
  int info;
  struct lista *prox;
};

Lista cria_lista()
{
  return NULL;
}
int lista_vazia(Lista *lst) { return ((*lst) == NULL); }

int insere_final(Lista *lst, int elem)
{
  Lista N = (Lista)malloc(sizeof(struct lista));
  if (N == NULL)
    return 0;
  N->info = elem;
  if (lista_vazia(lst))
  {
    N->prox = N;
    *lst = N;
  }
  else
  {
    N->prox = (*lst)->prox;
    (*lst)->prox = N;
    (*lst) = N;
  }
  return 1;
}

int insere_inicio(Lista *lst, int elem)
{
  Lista N = (Lista)malloc(sizeof(struct lista));
  if (!N)
    return 0;
  N->info = elem;
  if (lista_vazia(lst))
  {
    N->prox = N;
    *lst = N;
  }
  else
  {
    N->prox = (*lst)->prox;
    (*lst)->prox = N;
    // (*lst) = N;
  }
  return 1;
}
int remove_inicio(Lista *lst, int *elem)
{
  if (lista_vazia(lst))
    return 0;
  Lista aux = (*lst)->prox;
  *elem = aux->info;
  if (*lst == (*lst)->prox)
    *lst = NULL;
  else
    (*lst)->prox = aux->prox;
  free(aux);
  return 1;
}
int remove_final(Lista *list, int *elem)
{
  if (lista_vazia(list))
    return 0;
  *elem = (*list)->info;
  Lista aux = (*list)->prox;
  if (*list == (*list)->prox)
  {
    *list = NULL;
    free(aux);
  }
  else
  {
    while (aux->prox->prox != (*list)->prox)
      aux = aux->prox;
    aux->prox = (*list)->prox;
    free(*list);
    *list = aux;
  }
  return 1;
}
int obtem_valor_elem(Lista *list, int indice, int *elem)
{
  if (indice < 0 || lista_vazia(list))
    return 0;
  Lista aux = (*list)->prox;
  while (indice > 0 && aux->prox != (*list)->prox)
  {
    aux = aux->prox;
    indice--;
  }
  if (!indice)
  {
    *elem = aux->info;
    return 1;
  }
  return 0;
}

// int obtem_tamanho(Lista *lst) { return ((*lst)->info); }