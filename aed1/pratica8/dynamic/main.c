#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // SOMENTE PARA SISTEMAS SUPERIORES
#include "pilha.h"
#define tam 1

void print_pilha(DynamicStack p, int *array)
{
  array = (int *)malloc(sizeof(int) * (stack_size(&p)));
  int i = 0;
  while (pop(&p, &array[i]))
  {
    printf(" [%d]", array[i]);
    i++;
  }
  while (i--)
    push(&p, array[i]);
  free(array);
}
int main(int argc, char const *argv[])
{
  int option = 1, continuar = 1, tmp = 0, /*tmp2 = 0,*/ qnt_pilha = 0, *array, numero;
  DynamicStack stack[tam];
  int stack_ocupados[tam] = {0};
  while (continuar)
  {
    printf("1: Criar pilha stack\n");
    printf("2: Insere na pilha\n");
    printf("3: Remove no topo\n");
    printf("4: Printa pilha\n");
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

        stack[i] = create_stack();
        printf("Pilha %d criada com sucesso\n", i);
        stack_ocupados[i]++;
        qnt_pilha++;
      }
      else
      {
        printf("Quantidade maximas de pilhas criadas tente outro comando\n");
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
      printf("Insira a numero que deseja inserir na pilha %d: ", tmp);
      setbuf(stdin, NULL);
      scanf("%d", &numero);
      if (push(&stack[tmp], numero))
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
      if (pop(&stack[tmp], &numero))
      {
        printf("Sucesso, %d removido\n", numero);
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
      array = (int *)malloc(sizeof(int) * stack_size(&stack[tmp]));
      if (get_stack(&stack[tmp], array))
      {
        printf("Pilha %d:[", tmp);
        for (size_t i = 0; i < stack_size(&stack[tmp]); i++)
          printf(" %d", array[i]);
        printf(" ]\n");
      }
      else
        printf("Erro\n");
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