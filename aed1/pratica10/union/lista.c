#include "lista.h"
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 20
typedef struct
{
  int type;
  // 0-> FLOAT
  // 1-> CHAR
  union
  {
    float i_float;
    char i_char;
  } info;

} nota;

struct lista
{
  nota no[MAX_SIZE];
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
  return (lst->end == MAX_SIZE);
}

int insere_elem(Lista lst, Dados info)
{
  if (lst == NULL || lista_cheia(lst))
    return 0;
  if (info.type == 0) //float
  {
    lst->no[lst->end].info.i_float = info.f_info;
    lst->no[lst->end].type = info.type;
  }
  else if (info.type == 1) //char
  {
    lst->no[lst->end].info.i_char = info.c_info;
    lst->no[lst->end].type = info.type;
  }
  else //undefined
    return 0;
  lst->end++;
  return 1;
}

int remove_elem(Lista lst, Dados info)
{
  if ((lst == NULL || lista_vazia(lst)))
    return 0;

  if ((lst->no[lst->end].type == info.type))
  {
    if (info.type == 1 && (lst->no[lst->end].info.i_char == info.c_info)) //se é char
    {
      lst->end--;
      return 1;
    }
    else if (info.type == 0 && (lst->no[lst->end].info.i_float == info.f_info)) //se é float
    {
      lst->end--;
      return 1;
    }
  } //testando a ultima casa
  int aux = 0;
  while (aux < lst->end)
  {
    // if ((lst->no[lst->end].type == info.type) && ((lst->no[aux].info.i_char == info.c_info && info.type == 1) || (lst->no[aux].info.i_float == info.f_info && info.type == 0)))
    //   break;
    // aux++;
    if (lst->no[lst->end].type == info.type)
    {
      if (lst->no[aux].info.i_char == info.c_info && info.type == 1)
        break;
      else if (lst->no[aux].info.i_float == info.f_info && info.type == 0)
        break;
    }
    aux++;
  }
  if (aux == lst->end)
    return 0;
  for (size_t i = aux + 1; i < lst->end; i++)
    lst->no[i - 1] = lst->no[i];
  lst->end--;
  return 1;
}

int get_posicao(Lista lst, int num, Dados *info)
{
  if (lst == NULL || lst->end == 0 || num >= lst->end || lst->end <= 0)
    return 0;
  if (lst->no[num].type == 0) //float
  {
    (*info).type = 0;
    (*info).f_info = lst->no[num].info.i_float;
    return 1;
  }
  else if (lst->no[num].type == 1) //char
  {
    (*info).type = 1;
    (*info).c_info = lst->no[num].info.i_char;
    return 1;
  }
  return 0;
}
int get_size(Lista lst)
{
  return (lst->end);
}