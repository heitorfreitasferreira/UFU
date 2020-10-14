#include <stdlib.h>
#include "fila.h"
struct no
{
  Bebida info;
  struct no *prox;
};
struct fila
{
  struct no *beg;
  struct no *end;
};
Fila cria_fila()
{
  Fila queue;
  queue = (Fila)malloc(sizeof(struct fila));
  if (queue)
  {
    queue->end = NULL;
    queue->beg = NULL;
  }
  return queue;
}
int fila_vazia(Fila queue) { return (!(queue->beg)); }

int push(Fila queue, Bebida elem)
{
  struct no *q;
  q = (struct no *)malloc(sizeof(struct no));
  if (!q)
    return 0;
  q->info = elem;
  q->prox = NULL;
  if (fila_vazia(queue))
    queue->beg = q;
  else
    queue->end->prox = q;
  queue->end = q;
  return 1;
}

int shift(Fila queue, Bebida *elem)
{
  if (fila_vazia(queue))
    return 0;
  struct no *aux = queue->beg;
  *elem = aux->info;
  if (queue->beg == queue->end)
    queue->end = NULL;
  queue->beg = aux->prox;
  free(aux);
  return 1;
}
int apaga_fila(Fila *queue)
{
  struct no *aux = (*queue)->beg;
  struct no *aux2;
  while (aux != NULL && aux->prox != NULL)
  {
    aux2 = aux->prox;
    free(aux);
    aux = aux2;
  }
  free(*queue);
  *queue = NULL;
  return 1;
}

int esvazia_fila(Fila queue)
{
  struct no *aux = queue->beg;
  struct no *aux2;
  while (aux != NULL && aux->prox != NULL)
  {
    aux2 = aux->prox;
    free(aux);
    aux = aux2;
  }
  queue->beg = NULL;
  queue->end = NULL;
  return 1;
}
int tamanho_fila(Fila queue)
{
  struct no *aux = queue->beg;
  int i = 0;
  while (aux != NULL && aux->prox != NULL)
  {
    i++;
    aux = aux->prox;
  }
  return i;
}