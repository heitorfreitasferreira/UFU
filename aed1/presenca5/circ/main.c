#include <stdio.h>
#include <stdlib.h>
#include "listaDinCircular.h" //inclui os Prototipos

int main(){
  struct aluno a1;
  int op,v,mat,n;
  Lista* li = cria_lista();

  do{
    //system("cls");
    printf("        LISTA CIRCULAR ENCADEADA \n");
    printf("------------------------------------------\n\n");
    printf("Opcoes do Programa\n");
    printf("1. Inserir aluno no inicio da lista.\n");
    printf("2. Inserir aluno no final da lista.\n");
    printf("3. Listar os alunos e as suas medias.\n");
    printf("4. Buscar os dados de um aluno por matricula.\n");
    printf("5. Sortear um aluno em contagem circular.\n");
    printf("6. Remover um aluno.\n");
    printf("7. Gerar lista de aprovados (nota >= 70)\n");
    printf("8. Encerrar\n");
    printf("--> Informe a opcao desejada: ");
    scanf("%d",&op);

    switch(op){

    case 1:
        a1 = preenche_dados();
        v=insere_lista_inicio(li,a1);
        if (v==0) printf("\nNao houve modificacao na lista\n");
        else printf("\nAluno inserido no inicio da lista com sucesso\n");
        //system("pause");
        break;


    case 2:
        a1 = preenche_dados();
        v=insere_lista_final(li,a1);
        if (v==0) printf("\nNao houve modificacao na lista\n");
        else printf("\nAluno inserido no final da lista com sucesso\n");
        //system("pause");
        break;

    case 3:
        printf("\n\n ----- Lista de alunos (Media das notas) \n");
        imprime_lista(li);
        //system("pause");
        break;

    case 4:
        printf("\nInforme o numero de matricula: ");
        scanf("%d",&mat);
        v=consulta_lista_mat(li,mat,&a1);
        if (v==0) printf("\nNao foi encontrada esta matricula\n");
           else printf("\nAluno %s encontrado.\n",a1.nome);
        //system("pause");
        break;

    case 5:
        printf("\nInforme o numero para sorteio: ");
        scanf("%d",&n);
        v=sorteia_aluno(li,n,&a1);
        if (v==0) printf("\nNao foi encontrada esta matricula\n");
           else printf("\nAluno %s encontrado.\n",a1.nome);
        //system("pause");
        break;


    case 6:
        printf("\nInforme a matricula a ser removida: ");
        scanf("%d",&mat);
        v=remove_lista_matricula(li,mat);
        if (v==0) printf("\nNao houve modificacao na lista\n");
           else printf("\nAluno removido\n");
        //system("pause");
        break;


    case 7:
        printf("\nLista de Aprovados (Media >= 70): \n");
        imprime_lista_aprovados(li);
        //system("pause");
        break;


    case 8:
        libera_lista(li);
        break;


    default:
        printf("Opcao invalida!");
            break;
    }

    }while(op != 8);
}