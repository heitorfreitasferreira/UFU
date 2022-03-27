#include <iostream>
#define TAMANHO_RETICULADO 1024
using namespace std;
int main()
{
  int quantidade_quadrante_b = 0, quantidade_quadrante_a = 0, quantidade_quadrante_c = 0, quantidade_quadrante_d = 0;
  for (size_t i = 0; i < TAMANHO_RETICULADO; i++)
  {
    for (size_t j = 0; j < TAMANHO_RETICULADO; j++)
    {
      if (i < TAMANHO_RETICULADO / 2 && j < TAMANHO_RETICULADO / 2)
      {
        quantidade_quadrante_b++;
      }
      if (i < TAMANHO_RETICULADO / 2 && j >= TAMANHO_RETICULADO / 2)
      {
        quantidade_quadrante_a++;
      }
      if (i >= TAMANHO_RETICULADO / 2 && j < TAMANHO_RETICULADO / 2)
      {
        quantidade_quadrante_c++;
      }
      if (i >= TAMANHO_RETICULADO / 2 && j >= TAMANHO_RETICULADO / 2)
      {
        quantidade_quadrante_d++;
      }
    }
  }
  printf("Quantidade de quadrante A: %d", quantidade_quadrante_a);
  printf("Quantidade de quadrante B: %d", quantidade_quadrante_b);
  printf("Quantidade de quadrante C: %d", quantidade_quadrante_c);
  printf("Quantidade de quadrante D: %d", quantidade_quadrante_d);
}