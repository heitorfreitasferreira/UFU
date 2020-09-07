#include <stdio.h>
#include "lista.h"
#define tam 5
int main(int argc, char const *argv[])
{
  int option = 1, continuar = 1, lista_criada = 0, tmp = 0;
  Lista lst;
  while (continuar)
  {
    printf("1: Criar lista lst\n2: Insere na lista\n3: Remove primeira ocorrencia\n4:Remove segundo a posicao\n5:Imprimir lista\n6:  Sair\n\nOpcao: ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
      /* CRIANDO LISTA */
      if (lista_criada)
      {
        printf("Lista ja criada, tente outro comando\n");
      }
      else
      {
        lst = cria_lista();
        printf("Lista criada com sucesso\n");
        lista_criada = 1;
      }
      break;

    case 2:
      /* INSERINDO NA LISTA */
      printf("Insira o numero que deseja inserir\n");
      scanf("%d", &tmp);
      insere_ord(&lst, tmp);
      break;
    case 3:
      printf("Insira o numero que deseja remover\n");
      scanf("%d", &tmp);
      remove_ord(&lst, tmp);
      break;
    case 4:
      /* REMOVENDO POSIÇÃO */
      break;
    case 5:
      /* IMPRIMINDO LISTA */
      for (size_t i = 0; i < get_size(&lst); i++)
      {
        obtem_posicao(lst, i, &tmp);
        printf("%d ", tmp);
      }
      printf("\n");
      break;
    case 6:
      limpa_lista(&lst);
      continuar = 0;
      break;
    default:
      printf("Opcao invalida, tente novamente\n");
      break;
    }
  }

  return 0;
}
