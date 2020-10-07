#include <stdlib.h>
#include "pilha.h"
struct pilha
{
  int info;
  DynamicStack prox;
};
//Create a static stack
DynamicStack create_stack()
{
  return NULL;
}
//Checks if the stack is empty
int empty_stack(DynamicStack *p) { return (!(*p)); }

//Puts an element to the top of the stack
int push(DynamicStack *p, int elem)
{
  DynamicStack N = (DynamicStack)malloc(sizeof(struct pilha));
  if (!N)
    return 0;
  N->info = elem;
  N->prox = *p;
  *p = N;
  return 1;
}
//Remove the element from the top of the stack
int pop(DynamicStack *p, int *elem)
{
  if (!(*p))
    return 0;
  DynamicStack aux = (*p);
  *elem = aux->info;
  (*p) = aux->prox;
  free(aux);
  return 1;
}
//Returns in "elem" the element from the top of the stack without removing it
int get_top(DynamicStack *p, int *elem)
{
  if (!(*p))
    return 0;
  *elem = (*p)->info;
  return 1;
}

//FUNÇÕES EXTRA POWERED BY HEITOR

//Returns the size of the stack
int stack_size(DynamicStack *p)
{
  DynamicStack aux = *p;
  int i = 0;
  while (aux->prox)
  {
    aux = aux->prox;
    i++;
  }
  return i;
}
//Returns the entire stack in the pointer to int
int get_stack(DynamicStack *p, int *array)
{
  if (!(*p))
    return 0;

  DynamicStack aux = *p;
  int i = 0;
  while (aux->prox)
  {
    array[i] = aux->info;
    aux = aux->prox;
    i++;
  }
  return 1;
}