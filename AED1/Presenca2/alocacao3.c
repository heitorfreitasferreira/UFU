#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
  int **m, M;
  scanf("%d", &M);
  m = (int **)malloc(M * (sizeof(int *)));
  for (size_t i = 0; i < M; i++)
  {
    m[i] = (int *)malloc(M * (sizeof(int)));
  }
  for (size_t i = 0; i < M; i++)
  {
    for (size_t j = 0; j < M; j++)
    {
      scanf("%d", &m[i][j]);
    }
  }
  for (size_t i = 0; i < M; i++)
  {
    for (size_t j = 0; j < M; j++)
    {
      if (i <= j)
      {
        printf("%d ", m[i][j]);
      }
      else
      {
        printf("0 ");
      }
    }
    printf("\n");
  }
  for (size_t i = 0; i < M; i++)
  {
    free(m[i]);
  }
  free(m);
  return 0;
}
