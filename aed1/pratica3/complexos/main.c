#include <stdio.h>
#include <stdlib.h>
#include "complexos.h"

int main(int argc, char const *argv[])
{
  float real, imaginary;
  scanf("%f %f", &real, &imaginary);
  Complexos *C1 = cria_nro(real, imaginary);
  scanf("%f %f", &real, &imaginary);
  Complexos *C2 = cria_nro(real, imaginary);
  scanf("%f %f", &real, &imaginary);
  Complexos *C3 = cria_nro(real, imaginary);

  Complexos *C1minusC3 = subtracao(C1, C3);
  Complexos *result = mult(C1minusC3, C2);
  get_value(result, &real, &imaginary);
  printf("(C1 – C3) * C2 = %f %fi\n", imaginary, real);
}
