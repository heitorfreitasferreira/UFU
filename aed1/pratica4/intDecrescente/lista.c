#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
//estrutura para posicao de cada elemento
struct no
{
    int num;
    struct no *prox;
};
//cria a lista devolvendo NULL para uma lista vazia
Lista cria_lista()
{
    return NULL;
};
//verifica se a lista esta vazia olhando se o ponteiro da aplica��o aponta para NULL
int lista_vazia(Lista list)
{
    return list == NULL;
}
//insere um elemento de forma ordenada na lista
int insere_ord(Lista *list, int elem)
{
    //aloca um no da lista
    Lista N = (Lista)malloc(sizeof(struct no));
    //verifica se a alocacao foi bem sucedida
    if (N == NULL)
        return 0;
    //insere um num em no
    N->num = elem;
    //verifica se o local de insercao e no inicio da lista
    if (lista_vazia(*list) || elem <= (*list)->num)
    {
        //faz o no criado apontar pro 1 no da lista
        N->prox = *list;
        //faz a lista apontar para o no atual
        *list = N;
        return 1;
    }
    //percorrendo lista
    Lista aux = *list; //faz aux apontar pro 1 no
    while (aux->prox != NULL && aux->prox->num < elem)
        aux = aux->prox; // avanca na lista
    //insere na lista
    N->prox = aux->prox;
    aux->prox = N;
    return 1;
}
//remove um det elemento da lista
int remove_ord(Lista *list, int elem)
{
    //se a lista estiver vazia e o elemento nao estiver no inicio
    //nao ha como remover
    if (lista_vazia(*list) || elem < (*list)->num)
        return 0;
    //ponteiro para o primeiro no
    Lista aux = *list;
    //remove o elemento se este estiver no inicio da lista
    if (elem == (*list)->num)
    {
        *list = aux->prox;
        free(aux);
        return 1;
    }
    //percorrendo lista
    while (aux->prox != NULL && aux->prox->num < elem)
        aux = aux->prox; // avanca na lista
    //verifica se o elemento nao esta na lista
    if (aux->prox == NULL || aux->prox->num > elem)
        return 0;
    //remove no da lista
    Lista aux2 = aux->prox; //aponta o no a ser removido
    aux->prox = aux2->prox; //retira no da lista
    free(aux2);             // libera memoria alocada
    return 1;
}

//inefeciente para consultas, pois para cada posicao
//deve percorter a lista novamente
//o melhor seria retorna um ponteiro para o vetor com os dados da lista
//obtem o valor na posicao indice da lista
int obtem_posicao(Lista list, int indice, int *num)
{
    //aumenta para andar indice vezes na lista
    //verifica se a lista e valida
    if (lista_vazia(list) || indice < 0)
        return 0;
    //percorrendo lista
    while (list != NULL && indice--)
        list = list->prox; // avanca na lista
    //verifica se chegou fora da lista
    if (list == NULL)
        return 0;
    //retorna o valor do no em num
    *num = list->num;
    return 1;
}
//limpa a lista
int limpa_lista(Lista *list)
{
    //inicializa aux com o inicio da lista
    Lista aux = *list, aux2;
    //libera os elementos conforme percorre a lista
    while (aux != NULL)
    {
        aux2 = aux->prox; //variavel auxiliar
        free(aux);        //libera o no na lista

        aux = aux2; //passa para o proximo no
    }
    //a lista e limpada, entao ela aponta pra NULL
    *list = NULL;
    return 1;
}
int get_size(Lista *lst)
{
    if (lst == NULL)
        return 0;
    int count = 0;
    Lista aux = *lst;
    while (aux != NULL)
    {
        count++;
        aux = aux->prox;
    }
    return count;
}