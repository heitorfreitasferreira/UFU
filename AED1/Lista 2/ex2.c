#include <stdlib.h>
#include <stdio.h>

typedef struct
{
  char nome[20];
  int volume;
  float preco;
} Bebida;

int main(int argc, char const *argv[])
{
  Bebida **bebida;
  bebida = (Bebida **)malloc(20 * sizeof(Bebida *));
  int opcao = 4, tam = 0;
  while (tam < 20)
  {
    printf("Opcao: ");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1: //INSERIR REGISTRO
      bebida[tam] = (Bebida *)malloc(2 * sizeof(Bebida));
      printf("Nome: ");
      scanf("%s", bebida[tam][0].nome);
      setbuf(stdin, NULL);
      printf("Volume: ");
      scanf("%d", &bebida[tam][0].volume);
      setbuf(stdin, NULL);
      printf("Preco: ");
      scanf("%f", &bebida[tam][0].preco);
      setbuf(stdin, NULL);
      tam++;
      break;
    case 2: //APAGAR ULTIMO REGISTRO
      tam--;
      free(bebida[tam]);
      break;
    case 3: //IMPRIMIR TABELA
      printf("Bebida\t\t\tPreco\t\t\tTamanho\n");
      for (size_t i = 0; i < tam; i++)
      {
        printf("%s\t\t\t%.2f\t\t\t%d\n", bebida[i][0].nome, bebida[i][0].preco, bebida[i][0].volume);
      }
      break;
    case 4: //SAIR
      tam = 20;
      break;
    default:
      printf("Opcao nao eh valida\n");
      break;
    }
  }

  return 0;
}
