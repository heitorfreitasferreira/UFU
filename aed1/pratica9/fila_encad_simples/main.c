#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // SOMENTE PARA SISTEMAS SUPERIORES
#include "fila.h"
#define tam 1

void print_fila(Fila q, Bebida lista[])
{
  // array = (Aluno *)malloc(sizeof(Aluno) * get_size(q));
  int i = 0;
  while (!fila_vazia(q))
  {
    shift(q, &lista[i]);
    printf(" [Nome: \"%s\"\t|\tVolume: %d\t|\tPreco: %.2f]", lista[i].nome, lista[i].vol, lista[i].preco);
    printf("\n");
    i++;
  }
  int j = 0;
  while (j < i)
  {
    push(q, lista[j]);
    j++;
  }
}

int main(int argc, char const *argv[])
{
  int option = 1, continuar = 1, tmp = 0, /*tmp2 = 0,*/ qnt_pilha = 0;
  Bebida elem;
  Fila stack[tam];
  int stack_ocupados[tam] = {0};
  while (continuar)
  {
    printf("1: Criar fila stack\n");
    printf("2: Insere\n");
    printf("3: Remove\n");
    printf("4: Printa fila\n");
    printf("5: Esvazia fila\n");
    printf("6: Apaga fila\n");
    printf("7: Sair\n");
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
      printf("Nome: ");
      setbuf(stdin, NULL);
      scanf("%[^\n]", elem.nome);
      setbuf(stdin, NULL);
      printf("Volume: ");
      scanf("%d", &elem.vol);
      printf("Preco: ");
      scanf("%f", &elem.preco);
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

      Bebida array[1000];
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
      //ESVAZIA LISTA
      // printf("Qual fila deseja esvaziar");
      // for (size_t i = 0; i < qnt_pilha; i++)
      //   printf(" %ld", i);
      // printf(": ");
      // scanf("%d", &tmp);
      tmp = 0;

      if (esvazia_fila(stack[tmp]))
      {
        printf("Sucesso, fila %d esvaziada\n", tmp);
      }
      else
        printf("Erro\n");

      // sleep(2);
      // system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES

      break;
    case 6:
      //APAGA LISTA
      // printf("Qual fila deseja apagar");
      // for (size_t i = 0; i < qnt_pilha; i++)
      //   printf(" %ld", i);
      // printf(": ");
      // scanf("%d", &tmp);
      tmp = 0;

      if (apaga_fila(&stack[tmp]))
      {
        printf("Sucesso, fila %d apagada\n", tmp);
      }
      else
        printf("Erro\n");

      // sleep(2);
      // system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      break;
    case 7:
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