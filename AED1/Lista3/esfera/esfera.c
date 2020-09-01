#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "esfera.h"
#include "./ponto/ponto.h"
#define pi 3.14159265359

struct Esfera
{
  Ponto *ponto_a, *ponto_b;
};

Esfera *cria_esfera(float x1, float y1, float z1, float x2, float y2, float z2)
{
  Ponto *p1 = createPoint(x1, y1, z1);
  Ponto *p2 = createPoint(x2, y2, z2);

  Esfera *e = (Esfera *)malloc(sizeof(Esfera));
  if (!e)
    return 0;
  (*e).ponto_a = p1;
  e->ponto_b = p2;
  return e;
}

void libera_esfera(Esfera *e)
{
  freePoint(e->ponto_a);
  freePoint(e->ponto_b);
  free(e);
  e = NULL;
}

float raio(Esfera *e)
{
  return distancePoint(e->ponto_a, e->ponto_b);
}
float area(Esfera *e)
{
  return (4 * pi * raio(e) * raio(e));
}
double volume(Esfera *e)
{
  return ((area(e) * raio(e)) / 3);
}