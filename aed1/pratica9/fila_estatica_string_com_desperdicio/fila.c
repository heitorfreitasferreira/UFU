#include "fila.h"
#include <stdlib.h>
#include <string.h>

struct lista
{
  String no[max];
  int beg, end;
};
Fila cria_fila()
{
  Fila lst;
  lst = (Fila)malloc(sizeof(struct lista));
  if (lst)
  {
    lst->end = 0;
    lst->beg = 0;
  }
  return lst;
}

int fila_vazia(Fila lst)
{
  return (lst->end == lst->beg);
}

int fila_cheia(Fila lst)
{
  return (lst->beg == ((lst->end + 1) % max));
}

int push(Fila lst, char *elem)
{
  if (lst == NULL || fila_cheia(lst))
    return 0;
  strcpy(lst->no[lst->end].string, elem);
  lst->end = (lst->end + 1) % max;
  return 1;
}
int shift(Fila lst, char *elem)
{
  if (lst == NULL || fila_vazia(lst))
    return 0;
  strcpy(elem, lst->no[lst->beg].string);
  lst->beg = (lst->beg + 1) % max;
  return 1;
}
// int limpa_fila(Fila lst)
// {
//   if (lst == NULL)
//     return 0;
//   for (size_t i = 0; i < lst->end; i++)
//   {
//     lst->no[i] = 0;
//   }
//   lst->end = 0;
//   lst->beg = 0;
//   return 1;
// }

// float get_posicao(Fila lst, int num)
// {
//   if (lst == NULL | lista_vazia(lst))
//     return 0;
//   return lst->no[num];
// }
// int get_size(Fila lst)
// {
//   return (lst->end - lst->beg);
// }