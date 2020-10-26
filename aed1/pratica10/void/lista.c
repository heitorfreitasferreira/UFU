#include "lista.h"
#include <stdlib.h>
struct no
{
  int type;
  void *info;
  struct no *prox;
};
Lista cria_lista()
{
  return NULL;
}
int lista_vazia(Lista lst) { return (!lst); }

int insere_elem(Lista *lst, Dados info)
{
  Lista N = (Lista)malloc(sizeof(struct no));

  if (!N)
    return 0;

  if (info.type == 1)
  {
    char *c = (char *)malloc(sizeof(char));
    *c = info.c_info;
    N->info = c;
    N->type = 1;
    // (*(char *)N->info) = info.c_info;
  }
  else if (info.type == 0)
  {
    float *f = (float *)malloc(sizeof(float));
    *f = info.f_info;
    // (*(float *)N->info) = info.f_info;
    N->info = f;
    N->type = 0;
  }
  else
    return 0;
  N->prox = *lst;
  *lst = N;
  return 1;
}
int remove_elem(Lista *lst, Dados info)
{
  if (lista_vazia(*lst))
    return 0;
  Lista aux = *lst;
  //remove o elemento se este estiver no inicio da lista
  if (info.type == (*lst)->type)
  {
    if (info.c_info == (*(char *)(*lst)->info) || info.f_info == (*(float *)(*lst)->info))
    {
      *lst = aux->prox;
      free(aux);
      return 1;
    }
  }
  while (aux->prox != NULL /*|| (aux->prox->type != info.type && (info.c_info != (*(char *)aux->prox->info) && info.f_info != (*(float *)aux->prox->info)))*/)
  {
    if (aux->prox->type == info.type)
    {
      if (info.c_info == (*(char *)aux->prox->info) || info.f_info == (*(float *)aux->prox->info))
        break;
    }
    aux = aux->prox;
  }
  if (aux->prox == NULL)
    return 0;
  Lista aux2 = aux->prox;
  aux->prox = aux2->prox;
  free(aux2);
  return 1;
}

int get_posicao(Lista lst, int indice, Dados *info)
{
  if (lista_vazia(lst) || indice < 0)
    return 0;
  while (lst != NULL && indice--)
    lst = lst->prox;
  if (lst == NULL)
    return 0;
  info->type = lst->type;
  if (info->type == 1)
    info->c_info = (*(char *)lst->info);
  else if (info->type == 0)
    info->f_info = (*(float *)lst->info);
  return 1;
}
