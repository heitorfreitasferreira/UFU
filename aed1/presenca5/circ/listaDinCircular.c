/*
Executar o programa que implementa uma lista encadeada dinâmica circular contendo registros de alunos. 

1- Estude todo o código.
2- Implemente uma função para remover o primeiro elemento da lista.
3- Implemente uma função que elimine da lista todos os alunos com média inferior a 70, e os inclua numa nova lista.
4- Escreva uma função que encontre o aluno com a maior média.
*/

#include <stdio.h>
#include <stdlib.h>
#include "listaDinCircular.h" //inclui os Prototipos

//Definicao do tipo lista
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;


Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}


struct aluno preenche_dados(){
   struct aluno a;
   printf("\nInforme nro de matricula: ");
   scanf("%d",&a.matricula);
   printf("\nInforme nome: ");
   fflush(stdin);
   scanf("%s",a.nome);
   printf("\nDigite tres notas: ");
   fflush(stdin);
   scanf("%f%f%f",&a.n1, &a.n2, &a.n3);
   return a;
}


int sorteia_aluno(Lista* li, int n, struct aluno *al){
    if(li == NULL || (*li) == NULL || n <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    while(i < n){
        no = no->prox;
        i++;
    }
    *al = no->dados;
    return 1;
}

void libera_lista(Lista* li){
    if(li != NULL && (*li) != NULL){
        Elem *aux, *no = *li;
        while((*li) != no->prox){
            aux = no;
            no = no->prox;
            free(aux);
        }
        free(no);
        free(li);
    }
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL || (*li) == NULL)
        return 0;
    Elem *no = *li;
    while(no->prox != (*li) && no->dados.matricula != mat)
        no = no->prox;
    if(no->dados.matricula != mat)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem no = (Elem) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    if((*li) == NULL){//lista vazia: insere in�cio
        *li = no;
        no->prox = no;
    }else{
        Elem *aux = *li;
        while(aux->prox != (*li)){
            aux = aux->prox;
        }
        aux->prox = no;
        no->prox = *li;
    }
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem no = (Elem) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;


    no->dados = al;
    if((*li) == NULL){//lista vazia: insere in�cio
        *li = no;
        no->prox = no;
    }else{
        Elem *aux = *li;
        while(aux->prox != (*li)){
            aux = aux->prox;
        }
        aux->prox = no;
        no->prox = *li;
        *li = no;
    }
    return 1;
}


int remove_lista_matricula(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;
    Elem *no = *li;
    if(no->dados.matricula == mat){//remover do in�cio
        if(no == no->prox){//lista fica vaza
            free(no);
            *li = NULL;
            return 1;
        }else{
            Elem *ult = *li;
            while(ult->prox != (*li))//procura o �ltimo
                ult = ult->prox;
            ult->prox = (*li)->prox;
            *li = (*li)->prox;
            free(no);
            return 1;
        }
    }
    Elem *ant = no;
    no = no->prox;
    while(no != (*li) && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == *li)//n�o encontrado
        return 0;

    ant->prox = no->prox;
    free(no);
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL || (*li) == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    do{
        cont++;
        no = no->prox;
    }while(no != (*li));
    return cont;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}



void imprime_lista(Lista* li){
   Elem* no = *li;
   if(li == NULL || (*li) == NULL)
        return;
   do{
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %.1f %.1f %.1f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
   }while(no != (*li));
}

void imprime_lista_aprovados(Lista* li){
   Elem* no = *li;
   float media;
   if(li == NULL || (*li) == NULL)
        return;
   do{
        media = (no->dados.n1 + no->dados.n2 + no->dados.n3)/3.0;
        if (media >=70){
          printf("Matricula: %d\n",no->dados.matricula);
          printf("Nome: %s\n",no->dados.nome);
          printf("Media: %.1f\n",media);
          printf("-------------------------------\n");
        }
        no = no->prox;
   }while(no != (*li));
}