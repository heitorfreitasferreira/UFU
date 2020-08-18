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
void lerArray(int vet[], int tamanho)
{
  for (size_t i = 0; i < tamanho; i++)
  {
    scanf("%d", &vet[i]);
  }
}
int main(int argc, char const *argv[])
{
  int count, *vet;
  scanf("%d", &count);

  vet = (int *)malloc(count * sizeof(int));
  lerArray(vet, count);
  printArray(vet, count);
  int acum = 0;
  for (size_t i = 0; i < count; i++)
  {
    if (vet[i] % 2 != 0)
      acum += vet[i];
  }
  printf("Media impares: %d\n", acum);

  free(vet);
  return 0;
}
