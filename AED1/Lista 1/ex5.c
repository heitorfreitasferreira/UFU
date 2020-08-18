#include <stdio.h>
#include <stdlib.h>
void printArray(int vet[], int tamanho)
{
  printf("[ ");
  for (size_t i = 0; i < tamanho; i++)
  {
    if (i != tamanho - 1)
      // cout << vet[i] << ",";
      printf("%d, ", vet[i]);
    else
      // cout << vet[i] << endl;
      printf("%d", vet[i]);
  }
  printf(" ]\n");
}
void sort(int *v, int tam, int num)
{
  int i;
  for (i = 0; i < tam; i++)
  {
    if (v[i] == 0)
    {
      v[i] = num;
      break;
    }
    if (num < v[i] && tam - 1 < 30)
    {
      int j = tam - 2;
      while (j >= i)
      {
        v[j + 1] = v[j];
        j--;
      }
      v[i] = num;
      break;
    }
  }
}
int main(int argc, char const *argv[])
{
  if (argc != 2)
  {
    printf("Parametro de entrada main errado!");
    return 0;
  }
  int tam = atoi(argv[1]);
  if (tam > 30)
  {
    printf("Não é permitido maior que 30 numeros!");
    return 0;
  }
  // // int /*  *vet ,*/ i, j;
  // // vet = (int *)malloc(tam * sizeof(int));
  // int *aux, tmp;
  // // aux = (int *)malloc(sizeof(int));
  // // for (size_t i = 0; i < tam; i++)
  // //   vet[i] = 0;
  // // printArray(vet, tam);
  // for (int i = 0; i < tam; i++)
  // {
  //   scanf("%d", &tmp);
  //   aux = realloc(aux, (i + 1) * (sizeof(int)));
  //   aux[i] = tmp;

  //   bubbleSort(aux, i + 1);

  //   // for (size_t j = 0; j < tamAux; j++)
  //   // {
  //   //   vet[j] = aux[j];
  //   // }
  //   // for (size_t i = tamAux; i < tam; i++)
  //   //   vet[i] = 0;
  //   printf("aux: ");
  //   printArray(aux, i + 1);
  //   // printf("vet: ");
  //   // printArray(vet, tam);
  //   free(aux);
  //   // if (i == 0)
  //   // {
  //   //   vet[i] = tmp;
  //   // }
  //   // else
  //   // {
  //   //   if (tmp >= vet[i])
  //   //   {
  //   //     vet[i + 1] = tmp;
  //   //   }
  //   //   else
  //   //   {
  //   //     int aux =
  //   //     vet =
  //   //   }
  //   // }
  // }
  // free(vet);
  int vetor[30] = {0}, num, ordenaTam = 0, i;
  for (i = 0; i < tam; i++)
  {
    scanf("%d", &num);
    ordenaTam++;
    sort(vetor, ordenaTam, num);
    printArray(vetor, ordenaTam);
  }
  return 0;
}
