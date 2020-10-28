#include <stdlib.h>
#include "fila.h"
//Estrutura para posicao de cada elemento
struct no
{
  Aluno info;
  struct no *prox;
};
//Cria a Fila
Fila cria_fila() { return NULL; }
//Verifica se a Fila esta vazia
int fila_vazia(Fila *lst) { return (*lst) == NULL; }
//Insere um elemento no final da Fila
int push(Fila *lst, Aluno elem)
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
//Remove um elemento do início da Fila
int shift(Fila *lst, Aluno *elem)
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