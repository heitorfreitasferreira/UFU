#include "lista.h"
#include <stdlib.h>
#include <string.h>
#define max 20
struct bebida
{
  char nome[20];
  int vol;
  float preco;
};

struct lista
{
  struct bebida no[max];
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

// int insere_elem(Lista lst, char *str, int vol, float preco)
// {
//   if (lst == NULL || lista_cheia(lst))
//     return 0;
//   // lst->no[lst->end] = num;
//   strcpy(lst->no[lst->end].nome, str);
//   lst->no[lst->end].preco = preco;
//   lst->no[lst->end].vol = vol;
//   lst->end++;
//   return 1;
// }
// int remove_elem(Lista lst, char *str)
// {
//   if (lst == NULL || lista_vazia(lst))
//     return 0;
//   if (strcmp(lst->no[lst->end].nome, str) == 0)
//   {
//     strcpy(lst->no[lst->end].nome, '0');
//     lst->no[lst->end].vol = 0;
//     lst->no[lst->end].preco = 0;
//     lst->end--;
//     return 1;
//   }
//   int aux = 0;
//   while ((aux < lst->end) && (strcmp(lst->no[aux].nome, str) == 0))
//     aux++;
//   if (aux == lst->end)
//     return 0;
//   for (size_t i = aux + 1; i < lst->end; i++)
//     lst->no[i - 1] = lst->no[i];
//   lst->end--;
//   return 1;
// }
int comparar(char *str1, char *str2, int vol1, int vol2)
{
  int res = strcmp(str1, str2);
  if (res)
    return res < 0;
  return vol2 >= vol1;
}
int insere_elem(Lista lst, char *str, int vol, float preco)
{
  if (lst == NULL || lista_cheia(lst))
    return 0;
  if (lista_vazia(lst) || comparar(lst->no[lst->end - 1].nome, str, lst->no[lst->end - 1].vol, vol))
  {
    lst->no[lst->end].preco = preco;
    lst->no[lst->end].vol = vol;
    strcpy(lst->no[lst->end].nome, str);
  }
  else
  {
    int aux = 0;
    while (comparar(lst->no[aux].nome, str, lst->no[aux].vol, vol))
      aux++;
    for (size_t i = lst->end; i > aux; i--)
      lst->no[lst->end] = lst->no[lst->end - 1];
    lst->no[lst->end].preco = preco;
    lst->no[lst->end].vol = vol;
    strcpy(lst->no[lst->end].nome, str);
  }
  lst->end++;
  return 1;
}
int remove_elem(Lista lst, char *str)
{
  if (lst == NULL || lista_vazia(lst) || strcmp(lst->no[0].nome, str) > 0 || strcmp(lst->no[lst->end - 1].nome, str) < 0)
    return 0;
  int aux = 0;
  while ((aux < lst->end) && strcmp(lst->no[aux].nome, str) < 0)
    aux++;
  if (aux == lst->end || strcmp(lst->no[aux].nome, str) > 0)
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
    lst->no[i].vol = 0;
    lst->no[i].preco = 0;
    strcpy(lst->no[i].nome, "NULL");
  }
  lst->end = 0;
  return 1;
}

int get_posicao(Lista lst, int num, char *str, int *vol, float *preco)
{
  if (lst == NULL || lst->end == 0 || num > lst->end || lst->end <= 0)
    return 0;
  strcpy(str, lst->no[num].nome);
  *vol = lst->no[num].vol;
  *preco = lst->no[num].preco;
  return 1;
}
int get_size(Lista lst)
{
  return (lst->end);
}