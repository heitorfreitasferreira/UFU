#include "lista.h"
#include <stdlib.h>
#include <string.h>
#define max 20
struct str
{
  char string[11];
};
typedef struct str String;
struct lista
{
  String no[max];
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

int lista_vazia(Lista lst)
{
  return (lst->end == 0);
}

int lista_cheia(Lista lst)
{
  return (lst->end == max);
}

int insere_elem(Lista lst, char *str)
{
  if (lst == NULL || lista_cheia(lst))
    return 0;
  // lst->no[lst->end] = num;
  strcpy(lst->no[lst->end].string, str);
  lst->end++;
  return 1;
}
int remove_elem(Lista lst, char *str)
{
  if (lst == NULL || lista_vazia(lst))
    return 0;
  if (strcmp(lst->no[lst->end].string, str) == 0)
  {
    // lst->no[lst->end].string = "NULL";
    lst->end--;
    return 1;
  }
  int aux = 0;
  while ((aux < lst->end) && (strcmp(lst->no[aux].string, str) == 0))
    aux++;
  if (aux == lst->end)
    return 0;
  for (size_t i = aux + 1; i < lst->end; i++)
    lst->no[i - 1] = lst->no[i];
  lst->end--;
  return 1;
}
int limpa_lista(Lista lst)
{
  if (lst == NULL)
    return 0;
  for (size_t i = 0; i < lst->end; i++)
  {
    strcpy(lst->no[i].string, "NULL");
  }
  lst->end = 0;
  return 1;
}

int get_posicao(Lista lst, int num, char *str)
{
  if (lst == NULL || lst->end == 0 || num > lst->end || lst->end <= 0)
    return 0;
  strcpy(str, lst->no[num].string);
  return 1;
}
int get_size(Lista lst)
{
  return (lst->end);
}