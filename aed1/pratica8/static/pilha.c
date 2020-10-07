#include <stdlib.h>
#include "pilha.h"
struct pilha
{
  int vetor[max];
  int topo;
};
//Create a static stack
StaticStack create_stack()
{
  StaticStack p;
  p = (StaticStack)malloc(sizeof(struct pilha));
  if (p)
    p->topo = -1;
  return p;
}
//Checks if the stack is empty
int empty_stack(StaticStack p) { return (p->topo == -1); }

//Checks if the stack is full
int full_stack(StaticStack p) { return (p->topo == max - 1); }

//Puts an element to the top of the stack
int push(StaticStack p, int elem)
{
  if (!p || (p->topo == max - 1))
    return 0;
  p->topo++;
  p->vetor[p->topo] = elem;
  return 1;
}
//Remove the element from the top of the stack
int pop(StaticStack p, int *elem)
{
  if (!p || (p->topo == -1))
    return 0;
  *elem = p->vetor[p->topo];
  // p->vetor[p->topo] = 0;//Opcional
  p->topo--;
  return 1;
}
//Returns in "elem" the element from the top of the stack without removing it
int get_top(StaticStack p, int *elem)
{
  if (!p || (p->topo == -1))
    return 0;
  *elem = p->vetor[p->topo];
  return 1;
}

//FUNÇÕES EXTRA POWERED BY HEITOR

//Returns the size of the stack
int stack_size(StaticStack p) { return (p->topo + 1); }
//Returns the entire stack in the pointer to int
int get_stack(StaticStack p, int *array)
{
  if (p->topo == -1)
    return 0;
  for (size_t i = 0; i < (p->topo + 1); i++)
    array[i] = p->vetor[i];
  return 1;
}