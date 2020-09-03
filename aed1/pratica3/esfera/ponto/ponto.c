#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ponto.h"

struct Ponto
{
  float x, y, z;
};

Ponto *createPoint(float x, float y, float z)
{
  Ponto *p = (Ponto *)malloc(sizeof(Ponto));
  if (!p)
    return 0;
  (*p).x = x;
  p->y = y;
  p->z = z;
  return p;
}

void freePoint(Ponto *p)
{
  free(p);
  p = NULL;
}

float distancePoint(Ponto *p1, Ponto *p2)
{
  double dx = p1->x - p2->x;
  double dy = p1->y - p2->y;
  double dz = p1->z - p2->z;
  return sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2));
}