#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"
int main(int argc, char const *argv[])
{
  float x, y;
  printf("X e Y do primeiro ponto: ");
  scanf("%f %f", &x, &y);
  Point *ponto1 = createPoint(x, y);

  printf("X e Y do segundo ponto: ");
  scanf("%f %f", &x, &y);
  Point *ponto2 = createPoint(x, y);

  printf("A distancia entre os pontos e de: %f\n", distancePoint(ponto1, ponto2));
  freePoint(ponto1);
  freePoint(ponto2);

  return 0;
}
