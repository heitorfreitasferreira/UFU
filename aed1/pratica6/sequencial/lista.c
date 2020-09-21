#include "lista.h"
#include <stdlib.h>
struct lista
{
  int info;
  struct lista *prox;
  struct lista *ant;
};

Lista cria_lista()
{
  return NULL;
}
int lista_vazia(Lista *lst) { return ((*lst) == NULL); }

int insere_elem(Lista *lst, int elem)
{
  Lista N = (Lista)malloc(sizeof(struct lista));
  if (!N)
    return 0;
  N->info = elem;
  N->ant = NULL;
  N->prox = (*lst);
  if (!lista_vazia(lst))
    (*lst)->ant = N;
  (*lst) = N;
  return 1;
}

int insere_ord(Lista *lst, int elem)
{
  Lista N = (Lista)malloc(sizeof(struct lista));
  if (N == NULL)
    return 0;
  N->info = elem;
  if (lista_vazia(lst) || (*lst)->info >= elem)
  {
    N->ant = NULL;
    N->prox = *lst;
    if (!lista_vazia(lst))
      (*lst)->ant = N;
    *lst = N;
    return 1;
  }
  Lista aux = *lst;
  while (aux->prox != NULL && aux->info < elem)
    aux = aux->prox;
  //insere no final
  if (aux->prox == NULL && aux->info < elem)
  {
    N->prox = NULL;
    N->ant = aux;
    aux->prox = N;
    return 1;
  }
  //insere no meio da lista
  N->prox = aux;
  N->ant = aux->ant;
  aux->ant = N;
  N->ant->prox = N;
  //sucesso, retorna flag 1
  return 1;
}

int remove_elem(Lista *lst, int elem)
{
  if (lista_vazia(lst))
    return 0;
  Lista aux = (*lst)->prox;

  while ((aux->prox) && aux->info != elem)
    aux = aux->prox;
  if (aux->info != elem)
    return 0;
  if (aux->prox != NULL)
    aux->prox->ant = aux->ant;
  if (aux->ant != NULL)
    aux->ant->prox = aux->prox;
  if (aux == *lst)
    *lst = aux->prox;
  free(aux);
  return 1;
}
int remove_ord(Lista *lst, int elem)
{
  if (lista_vazia(lst))
    return 0;
  Lista aux = (*lst)->prox;
  if ((*lst)->info > elem)
    return 0;
  while ((aux->prox != NULL) && aux->info != elem && aux->info < elem)
    aux = aux->prox;
  if (aux->info > elem)
    return 0;
  if (aux->prox != NULL)
    aux->prox->ant = aux->ant;
  if (aux->ant != NULL)
    aux->ant->prox = aux->prox;
  if (aux == *lst)
    *lst = aux->prox;
  free(aux);
  return 1;
}
int obtem_valor_elem(Lista *lst, int index, int *result)
{
  if (lista_vazia((lst)) || index < 0)
    return 0;
  Lista aux = (*lst)->prox;
  while (aux != NULL && index--)
    aux = aux->prox;
  if (aux == NULL)
    return 0;
  *result = aux->info;
  return 1;
}
// int obtem_tamanho(Lista *lst) { return ((*lst)->info); }