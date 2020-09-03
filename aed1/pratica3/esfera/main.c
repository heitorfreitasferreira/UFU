#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "esfera.h"
int main(int argc, char const *argv[])
{
  float x1, y1, z1;
  float x2, y2, z2;
  printf("X, Y e Z do primeiro ponto: ");
  scanf("%f %f %f", &x1, &y1, &z1);

  printf("X, Y e Z do segundo ponto: ");
  scanf("%f %f %f", &x2, &y2, &z2);
  Esfera *e = cria_esfera(x1, y1, z1, x2, y2, z2);

  printf("Raio: %f\nArea: %f\nVolume: %lf\n", raio(e), area(e), volume(e));

  return 0;
}
