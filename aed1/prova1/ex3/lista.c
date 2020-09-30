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
int esvaziar_lista(Lista *lst)
{
  if (lista_vazia(*lst) == 1)
    return 0;

  while ((*lst)->prox != NULL)
  {
    Lista aux = *lst;
    *lst = (*lst)->prox;
    free(aux);
  }
  free(*lst);
  *lst = NULL;
  return 1;
}
int insere_elem(Lista *lst, char elem)
{
  Lista N = (Lista)malloc(sizeof(struct no));
  if (!N)
    return 0;
  N->info = elem;
  N->prox = *lst;
  *lst = N;
  return 1;
}
int maior_elem(Lista *lst)
{
  if (lista_vazia(*lst))
    return 0;

  int maior = (*lst)->info;
  Lista aux = (*lst)->prox;
  while (aux->prox != NULL)
  {
    if (aux->info > maior)
      maior = aux->info;
    aux = aux->prox;
  }
  return maior;
}
int intercalar(Lista *lst1, Lista *lst2, Lista *lst3)
{
  if (lista_vazia(*lst1) || (*lst1)->prox == NULL || lista_vazia(*lst2) || (*lst2)->prox == NULL)
    return 0;

  Lista auxMaior;
  Lista auxMenor;
  if (maior_elem(lst1) > maior_elem(lst2))
  {
    auxMenor = (*lst2)->prox;
    auxMaior = (*lst1)->prox;
  }
  else
  {
    auxMenor = (*lst1)->prox;
    auxMaior = (*lst2)->prox;
  }
  int flag = 1;
  while (auxMenor != NULL)
  {
    if (!insere_elem(lst3, auxMenor->info) || !insere_elem(lst3, auxMaior->info))
    {
      flag = 0;
      esvaziar_lista(lst3);
      return flag;
    }

    auxMenor = auxMenor->prox;
    auxMaior = auxMaior->prox;
  }
  while (auxMaior != NULL)
  {
    if (insere_elem(lst3, auxMaior->info))
    {
      flag = 0;
      esvaziar_lista(lst3);
      return flag;
    }
    auxMaior = auxMaior->prox;
  }
  return 1;
}