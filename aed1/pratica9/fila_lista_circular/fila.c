#include <stdlib.h>
#include "fila.h"
//Estrutura para posicao de cada elemento
struct no
{
  double info;
  struct no *prox;
};
//Cria a Fila
Fila cria_fila() { return NULL; }
//Verifica se a Fila esta vazia
int fila_vazia(Fila *lst) { return (*lst) == NULL; }
//Insere um elemento no final da Fila
int insere_final(Fila *lst, double elem)
{
  Fila N = (Fila)malloc(sizeof(struct no));
  if (N == NULL)
    return 0;
  N->info = elem;
  if (Fila_vazia(lst))
  {
    N->prox = N;
    *lst = N;
  }
  else
  {
    N->prox = (*lst)->prox;
    (*lst)->prox = N;
    *lst = N;
  }
  return 1;
}
//Insere um elemento no início de uma Fila
int insere_inicio(Fila *lst, double elem)
{
  Fila N = (Fila)malloc(sizeof(struct no));
  if (N == NULL)
    return 0;
  N->info = elem;
  if (Fila_vazia(lst))
  {
    N->prox = N;
    *lst = N;
  }
  else
  {
    N->prox = (*lst)->prox;
    (*lst)->prox = N;
  }
  return 1;
}
//Remove um elemento do início da Fila
int remove_inicio(Fila *lst, double *elem)
{
  if (Fila_vazia(lst))
    return 0;
  Fila aux = (*lst)->prox;
  *elem = aux->info;
  if (*lst == (*lst)->prox)
    *lst = NULL;
  else
    (*lst)->prox = aux->prox;
  free(aux);
  return 1;
}
//Remove um elemento do fim da Fila
int remove_final(Fila *lst, double *elem)
{
  if (fila_vazia(lst))
    return 0;
  *elem = (*lst)->info;
  Fila aux = (*lst)->prox;
  if (*lst == (*lst)->prox)
  {
    *lst = NULL;
    free(aux);
  }
  else
  {
    while (aux->prox->prox != (*lst)->prox)
      aux = aux->prox;
    aux->prox = (*lst)->prox;
    free(*lst);
    *lst = aux;
  }
  return 1;
}
//Obtem o valor do elemento de uma Fila no indice especificado
int obtem_valor_elem(Fila *lst, int indice, double *elem)
{
  if (indice < 0 || fila_vazia(lst))
    return 0;
  Fila aux = (*lst)->prox;
  while (indice > 0 && aux->prox != (*lst)->prox)
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
//Retorna o tamanho da Fila
int Fila_tam(Fila *lst)
{
  if (fila_vazia(lst))
    return 0;
  int cont = 1;
  Fila aux = (*lst)->prox;
  while (aux->prox != (*lst)->prox)
  {
    aux = aux->prox;
    cont++;
  }
  return cont;
}
//Insere em determinada posição
int insere_pos(Fila *lst, int index, double elem)
{
  if (index < 0 || fila_vazia(lst) || index >= Fila_tam(lst))
    return 0;
  //Daqui pra frente existe a posição da Fila que deseja-se colocar
  Fila N = (Fila)malloc(sizeof(struct no));
  if (N == NULL)
    return 0;
  N->info = elem;
  N->prox = NULL;
  Fila aux = (*lst)->prox;
  while (index--)
    aux = aux->prox;
  N->prox = aux->prox;
  aux->prox = N;
  return 1;
}
//Remove em determinda posição
int remove_pos(Fila *lst, int index, double *elem)
{
  if (fila_vazia(lst))
    return 0;
  //Percorro até a posição pos
  while (index > 0)
  {
    *lst = (*lst)->prox;
    index--;
  }
  //Retorna o nome removido
  *elem = (*lst)->prox->info;
  Fila aux2 = (*lst)->prox;
  (*lst)->prox = aux2->prox;
  free(aux2);
  return 1;
}
//Obtem o maior elemento da Fila
int maior_elem(Fila *lst, double *elem)
{
  if (fila_vazia(lst))
    return 0;
  int maior = (*lst)->info;
  Fila aux = (*lst)->prox;
  while (aux->prox != (*lst)->prox)
  {
    if (aux->info > maior)
      maior = aux->info;

    aux = aux->prox;
  }
  *elem = maior;
  return 1;
}