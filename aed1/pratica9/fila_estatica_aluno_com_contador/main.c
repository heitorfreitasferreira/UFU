#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // SOMENTE PARA SISTEMAS SUPERIORES
#include "fila.h"
#define tam 1

void print_fila(Fila q, Aluno lista[max])
{
  // array = (Aluno *)malloc(sizeof(Aluno) * get_size(q));
  int i = 0;
  while (!fila_vazia(q))
  {
    shift(q, &lista[i]);
    printf(" [Nome: \"%s\"\t|\tMatricula: %d\t|\tFaltas: %d\t|\tMedia: %f]", lista[i].nome, lista[i].matricula, lista[i].faltas, lista[i].media);
    printf("\n");
    i++;
  }
  int j = 0;
  while (j < i)
  {
    push(q, lista[j]);
    j++;
  }
  // free(array);
}

int main(int argc, char const *argv[])
{
  int option = 1, continuar = 1, tmp = 0, /*tmp2 = 0,*/ qnt_pilha = 0;
  Aluno elem;
  Fila stack[tam];
  int stack_ocupados[tam] = {0};
  while (continuar)
  {
    printf("1: Criar fila stack\n");
    printf("2: Insere\n");
    printf("3: Remove\n");
    printf("4: Printa fila\n");
    printf("5: Sair\n");
    printf("\nOpcao: ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
      /* CRIANDO pilha */
      if (qnt_pilha < tam)
      {
        int i;
        for (i = 0; i < tam; i++)
        {
          if (stack_ocupados[i] == 0)
            break;
        }

        stack[i] = cria_fila();
        printf("Fila %d criada com sucesso\n", i);
        stack_ocupados[i]++;
        qnt_pilha++;
      }
      else
      {
        printf("Quantidade maximas de filas criadas tente outro comando\n");
      }
      // sleep(2);
      // system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      break;

    case 2:
      /* INSERINDO NA LISTA */

      // printf("Em qual pilha deseja inserir");
      // for (size_t i = 0; i < qnt_pilha; i++)
      //   printf(" %ld", i);
      // printf(": ");
      // scanf("%d", &tmp);
      tmp = 0;
      printf("Insira na fila %d\n", tmp);
      printf("Matricula: ");
      scanf("%d", &elem.matricula);
      printf("Faltas: ");
      scanf("%d", &elem.faltas);
      printf("Media: ");
      scanf("%f", &elem.media);
      printf("Nome: ");
      setbuf(stdin, NULL);
      scanf("%[^\n]", elem.nome);
      setbuf(stdin, NULL);
      if (push(stack[tmp], elem))
      {
        printf("Sucesso\n");
        // sleep(0.3);
        // system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      }
      else
      {
        printf("Erro\n");
        // sleep(2);
        // system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      }

      break;

    case 3:
      // printf("Em qual lista deseja remover");
      // for (size_t i = 0; i < qnt_pilha; i++)
      //   printf(" %ld", i);
      // printf(": ");
      // scanf("%d", &tmp);
      tmp = 0;
      // printf("Insira o numero que deseja remover: ");
      // setbuf(stdin, NULL);
      // scanf("%d", &numero);
      if (shift(stack[tmp], &elem))
      {
        printf("Sucesso, aluno %s removido\n", elem.nome);
        // sleep(0.3);
        // system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      }
      else
      {
        printf("Erro\n");
        // sleep(2);
        // system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      }
      break;
    case 4:
      /* IMPRIMINDO */
      // printf("Em qual lista deseja imprimir");
      // for (size_t i = 0; i < qnt_pilha; i++)
      //   printf(" %ld", i);
      // printf(": ");
      // scanf("%d", &tmp);
      tmp = 0;
      // array = (int *)malloc(sizeof(int) * stack_size(&stack[tmp]));

      Aluno array[max];
      print_fila(stack[tmp], array);

      // if (get_stack(&stack[tmp], array))
      // {
      //   printf("Pilha %d:[", tmp);
      //   for (size_t i = 0; i < stack_size(&stack[tmp]); i++)
      //     printf(" %d", array[i]);
      //   printf(" ]\n");
      // }
      // else
      //   printf("Erro\n");

      // sleep(2);
      // system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      break;
    case 5:
      //SAIR DO LOOP
      continuar = 0;
      break;
    default:
      printf("Opcao invalida, tente novamente\n");
      // sleep(1);
      // system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      break;
    }
  }
  return 0;
}