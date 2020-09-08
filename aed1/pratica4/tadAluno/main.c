#include <stdio.h>
#include "lista.h"
#define tam 5
int main(int argc, char const *argv[])
{
  int option = 1, continuar = 1, lista_criada = 0, tmpFaltas = 0;
  char tmpNome[20];
  unsigned int tmpMatricula;
  float tmpMedia;
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
      printf("Insira o num de matricula\n");
      scanf("%u", &tmpMatricula);
      printf("Insira o num de faltas\n");
      scanf("%d", &tmpFaltas);
      printf("Insira a media do aluno\n");
      scanf("%f", &tmpMedia);
      printf("Insira o nome do aluno\n");
      setbuf(stdin, NULL);
      scanf("%[^\n]s", tmpNome);
      setbuf(stdin, NULL);
      insere_elem(&lst, tmpMatricula, tmpNome, tmpMedia, tmpFaltas);
      break;
    case 3:
      printf("Insira o numero da matricula que deseja remover\n");
      scanf("%u", &tmpMatricula);
      if (remove_elem(&lst, tmpMatricula))
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
      for (size_t i = 0; i < obtem_tamanho(&lst); i++)
      {
        if (obtem_posicao(lst, i, &tmpMatricula, tmpNome, &tmpMedia, &tmpFaltas))
          printf("Nome: %s\tMatricula: %u\tMedia: %.2f\tFaltas: %d\n", tmpNome, tmpMatricula, tmpMedia, tmpFaltas);
        else
          printf("Aluno nao encontrado\n");
      }
      printf("\n\n");
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
