#include <stdio.h>
#include "lista.h"
#define tam 5
int main(int argc, char const *argv[])
{
  int option = 1, continuar = 1, lista_criada = 0, tmpVol = 0;
  char tmpNome[20];
  float tmpPreco = 0;
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
      if (lista_cheia(lst))
      {
        printf("Lista cheia, tente outro comando\n");
      }
      else
      {
        printf("Nome bebida: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", tmpNome);
        printf("Preco de %s: ", tmpNome);
        scanf("%f", &tmpPreco);
        printf("Volume de %s: ", tmpNome);
        scanf("%d", &tmpVol);
        // printf("%s\n%s\n", tmpNome, tmpNome);
        insere_elem(lst, tmpNome, tmpVol, tmpPreco);
      }
      break;
    case 3:
      printf("Insira a string que deseja remover\n");
      setbuf(stdin, NULL);
      scanf("%[^\n]s", tmpNome);
      setbuf(stdin, NULL);
      if (remove_elem(lst, tmpNome))
      {
      }
      else
      {
        printf("Matricula nao encontrada\n");
      }

      break;
    case 4:
      /* REMOVENDO POSIÇÃO */
      break;
    case 5:
      /* IMPRIMINDO LISTA */
      for (size_t i = 0; i < get_size(lst); i++)
      {
        if (get_posicao(lst, i, tmpNome, &tmpVol, &tmpPreco))
          printf("%s R$%.2f %dml\t", tmpNome, tmpPreco, tmpVol);
        else
          printf("Bebida nao encontrado\n");
      }
      printf("\n\n");
      break;
    case 6:
      limpa_lista(lst);
      continuar = 0;
      break;
    default:
      printf("Opcao invalida, tente novamente\n");
      break;
    }
  }

  return 0;
}
