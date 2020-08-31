#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"
int main(int argc, char const *argv[])
{
  float x, y, z;
  printf("X, Y e Z do primeiro ponto: ");
  scanf("%f %f %f", &x, &y, &z);
  Point *ponto1 = createPoint(x, y, z);

  printf("X, Y e Z do segundo ponto: ");
  scanf("%f %f %f", &x, &y, &z);
  Point *ponto2 = createPoint(x, y, z);

  printf("A distancia entre os pontos e de: %f\n", distancePoint(ponto1, ponto2));
  freePoint(ponto1);
  freePoint(ponto2);

  return 0;
}
