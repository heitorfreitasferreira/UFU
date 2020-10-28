#include <string.h>
#include <stdlib.h>
#include "lista.h"
struct no
{
    char num[15];
    struct no *prox;
};
Fila cria_lista()
{
    return NULL;
};
int fila_vazia(Fila list)
{
    return list == NULL;
}
int insere(Fila *list, char *str)
{
    Fila N = (Fila)malloc(sizeof(struct no));
    if (N == NULL)
        return 0;
    // N->num = elem;
    strcpy(N->num, str);
    if (fila_vazia(*list) || strcmp(str, (*list)->num) <= 0)
    {
        N->prox = *list;
        *list = N;
        return 1;
    }
    Fila aux = *list;
    while (aux->prox != NULL && strcmp(aux->prox->num, str) > 0)
        aux = aux->prox;
    N->prox = aux->prox;
    aux->prox = N;
    return 1;
}
int shift(Fila *queue, char *str)
{
    if (fila_vazia(*queue))
        return 0;
    Fila aux = *queue;
    strcpy(str, aux->num);
    *queue = aux->prox;
    free(aux);
    aux = NULL;
    return 1;
}