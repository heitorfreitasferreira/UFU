#include "lista.h"
#include <stdlib.h>
struct lista
{
  int info;
  struct lista *prox;
};

Lista cria_lista()
{
  Lista cab = (Lista)malloc(sizeof(struct lista));
  if (!cab)
  {
    cab->prox = NULL;
    cab->info = 0;
  }
  return cab;
}
int lista_vazia(Lista *lst) { return ((*lst)->prox == NULL); }

int insere_elem(Lista *lst, int elem)
{
  Lista N = (Lista)malloc(sizeof(struct lista));
  if (!N)
    return 0;
  N->info = elem;
  N->prox = (*lst)->prox;
  (*lst)->prox = N;
  (*lst)->info++;
  return 1;
}

int insere_ord(Lista *lst, int elem)
{
  Lista N = (Lista)malloc(sizeof(struct lista));
  if (N == NULL)
    return 0;
  N->info = elem;

  Lista aux = *lst;
  while (aux->prox != NULL && aux->prox->info < elem)
    aux = aux->prox;
  N->prox = aux->prox;
  aux->prox = N;
  (*lst)->info++;
  return 1;
}
int remove_elem(Lista *lst, int elem)
{
  if (lista_vazia(lst))
    return 0;
  Lista aux = (*lst)->prox;
  /*if (elem == (*lst)->info)
  {
    *lst = aux->prox;
    free(aux);
    return 1;
  }*/
  while ((!aux->prox) && aux->prox->info != elem)
    aux = aux->prox;
  if (!aux->prox)
  {
    return 0;
  }
  Lista aux2 = aux->prox;
  aux->prox = aux2->prox;
  free(aux2);
  (*lst)->info--;
  return 1;
}
// int remove_ord(Lista *lst, int elem)
// {
//   if (lista_vazia((lst)))
//     return 0;
//   Lista aux = (*lst);
//   while ((!aux->prox) && aux->prox->info < elem)
//     aux = aux->prox;
//   if ((!aux->prox) || aux->prox->info > elem)
//     return 0;
//   Lista aux2 = aux->prox;
//   aux->prox = aux2->prox;
//   free(aux2);
//   (*lst)->info--;
//   return 1;
// }
int remove_ord(Lista *lst, int elem)
{
  if (lista_vazia(lst) /*|| elem < (*lst)->info*/)
    return 0;

  Lista aux = (*lst)->prox;
  // if (elem == (*lst)->info)
  // {
  //   *lst = aux->prox;
  //   free(aux);
  //   return 1;
  // }
  // else
  // {
  while (aux->prox != NULL && aux->prox->info < elem)
    aux = aux->prox;
  if (aux->prox == NULL || aux->prox->info > elem)
    return 0;
  Lista aux2 = aux->prox;
  aux->prox = aux2->prox;
  free(aux2);
  return 1;
  // }
}
int obtem_valor_elem(Lista *lst, int index, int *result)
{
  if (lista_vazia((lst)) || index < 0 || index > (*lst)->info)
    return 0;
  Lista aux = (*lst)->prox;
  while (aux != NULL && index--)
    aux = aux->prox;
  if (aux == NULL)
    return 0;
  *result = aux->info;
  return 1;
}
int obtem_tamanho(Lista *lst) { return ((*lst)->info); }