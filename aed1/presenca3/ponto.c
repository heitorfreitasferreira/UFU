#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ponto.h"

struct Ponto
{
  float x, y;
};

Point *createPoint(float x, float y)
{
  Point *p = (Point *)malloc(sizeof(Point));
  if (!p)
    return 0;
  (*p).x = x;
  p->y = y;
  return p;
}

void freePoint(Point *p)
{
  free(p);
  p = NULL;
}

float distancePoint(Point *p1, Point *p2)
{
  double dx = p1->x - p2->x;
  double dy = p1->y - p2->y;
  return sqrt(pow(dx, 2) + pow(dy, 2));
}