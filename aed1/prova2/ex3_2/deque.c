#include "deque.h"
struct deque
{
  int no[max];
  int beg, end;
};
int decCircular(int i)
{
  if (i < 0)
    return max - 1;
  return i;
}
Deque cria_deque()
{
  Deque F = (Deque)malloc(sizeof(struct deque));

  if (F)
  {
    F->beg = 0;
    F->end = 0;
  }
  return F;
}
int deque_vazio(Deque fila)
{
  if (fila->end == fila->beg)
    return 1;
  return 0;
}
int deque_cheio(Deque fila)
{
  if (fila->beg == ((fila->end + 1) % max))
    return 1;
  return 0;
}

int insere_fim(Deque fila, int elem)
{
  if (deque_cheio(fila))
    return 0;
  fila->no[fila->end] = elem;
  fila->end = (fila->end + 1) % max;
  return 1;
}
int remove_ini(Deque fila, int *elem)
{
  if (deque_vazio(fila))
    return 0;
  *elem = fila->no[fila->beg];
  fila->beg = (fila->beg + 1) % max;
  return 1;
}
int remove_fim(Deque fila, int *elem)
{
  if (deque_vazio(fila))
    return 0;
  *elem = fila->no[fila->end];
  fila->end = ecCircular(fila->end);
  return 1;
}
int insere_ini(Deque fila, int elem)
{
  if (deque_cheio(fila))
    return 0;
  fila->beg = decCircular(fila->beg);
  fila->no[fila->beg] = elem;
  return 1;
}