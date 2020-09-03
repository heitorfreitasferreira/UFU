#include <stdio.h>
#include <stdlib.h>

void flatArray(char const **argsvet, int argc, int **vet)
{
  *vet = (int *)malloc((argc - 1) * sizeof(int));
  for (size_t i = 0; i < argc - 1; i++)
  {
    (*vet)[i] = atoi(argsvet[i + 1]);
  }
}
void printArray(int vet[], int tamanho)
{
  tamanho--;
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
float mediaArray(int vet[], int size)
{
  float media = 0;
  for (size_t i = 0; i < size; i++)
  {
    media += vet[i];
  }
  return media / size;
}
int acimaDaMedia(int vet[], int size)
{
  int acum = 0;
  for (size_t i = 0; i < size; i++)
  {
    if (vet[i] > mediaArray(vet, size))
    {
      acum++;
    }
  }
  return acum;
}
int main(int argc, char const *argv[])
{
  if (argc > 16)
  {
    printf("Finalizando programa pois numero de argumentos e grande demais\n");
    return 0;
  }

  int *vetorTratado;
  flatArray(argv, argc, &vetorTratado);
  printf("myArgs: ");
  printArray(vetorTratado, argc);
  printf("Media: %.2f\n", mediaArray(vetorTratado, argc - 1));
  printf("Quantidade de numeros que excedem a media %d\n", acimaDaMedia(vetorTratado, argc - 1));
  free(vetorTratado);
  return 0;
}