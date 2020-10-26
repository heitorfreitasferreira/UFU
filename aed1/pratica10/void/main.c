#include <stdio.h>
#include <stdlib.h>
// #include <unistd.h> // SOMENTE PARA SISTEMAS SUPERIORES
#include "lista.h"
#define tam 1

void print_fila(Lista lst)
{
  Dados info;
  int i = 0;
  while (get_posicao(lst, i, &info))
  {
    if (info.type == 0)
      printf("[%.2f]", info.f_info);
    else /*if (info.type == 1)*/
      printf("[%c]", info.c_info);
    i++;
  }
  printf("\n");
}

int main(int argc, char const *argv[])
{
  int option = 1, continuar = 1, tmp = 0, /*tmp2 = 0,*/ qnt_pilha = 0;
  Dados elem;
  Lista stack[tam];
  int stack_ocupados[tam] = {0};
  while (continuar)
  {
    printf("1: Criar lista\n");
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

        stack[i] = cria_lista();
        printf("Lista %d criada com sucesso\n", i);
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
      tmp = 0;
      printf("Insira na fila %d\n", tmp);
    type_error_insertion:
      printf("Insira 0 para Numerica e 1 para Conceitual: ");
      scanf("%d", &elem.type);
      if (elem.type == 0)
      {
        printf("Nota numerica: ");
        scanf("%f", &elem.f_info);
      }
      else if (elem.type == 1)
      {
        printf("Nota conceitual: ");
        setbuf(stdin, NULL);
        scanf("%c", &elem.c_info);
        setbuf(stdin, NULL);
      }
      else
      {
        setbuf(stdin, NULL);
        printf("Entrada invalida\n");
        goto type_error_insertion;
      }
      if (insere_elem(&stack[tmp], elem))
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
      tmp = 0;
      printf("Remova na fila %d\n", tmp);
    type_error_remove:
      printf("Insira 0 para Numerica e 1 para Conceitual: ");
      scanf("%d", &elem.type);
      if (elem.type == 0)
      {
        printf("Nota numerica: ");
        scanf("%f", &elem.f_info);
      }
      else if (elem.type == 1)
      {
        printf("Nota conceitual: ");
        setbuf(stdin, NULL);
        scanf("%c", &elem.c_info);
        setbuf(stdin, NULL);
      }
      else
      {
        setbuf(stdin, NULL);
        printf("Entrada invalida\n");
        goto type_error_remove;
      }
      if (remove_elem(&stack[tmp], elem))
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
    case 4:
      /* IMPRIMINDO */
      tmp = 0;

      print_fila(stack[tmp]);
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