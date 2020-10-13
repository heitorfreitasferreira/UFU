#include "fila.h"
#include <stdlib.h>
struct lista
{
  Aluno no[max];
  int beg, count;
};
Fila cria_fila()
{
  Fila queue;
  queue = (Fila)malloc(sizeof(struct lista));
  if (queue)
  {
    queue->count = 0;
    queue->beg = 0;
  }
  return queue;
}

int fila_vazia(Fila queue)
{
  return (!queue->count);
}

int fila_cheia(Fila queue)
{
  return (queue->count == max);
}

int push(Fila queue, Aluno elem)
{
  if (queue == NULL || fila_cheia(queue))
    return 0;
  queue->no[(queue->beg + queue->count) % max] = elem;

  queue->count++;
  return 1;
}
int shift(Fila queue, Aluno *elem)
{
  if (queue == NULL || fila_vazia(queue))
    return 0;
  *elem = queue->no[queue->beg];
  queue->beg = (queue->beg + 1) % max;
  queue->count--;
  return 1;
}

int get_size(Fila queue)
{
  return (queue->count);
}