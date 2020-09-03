#include <stdio.h>
#include <stdlib.h>
#include "complexos.h"

struct complexos
{
  float real, imaginario;
};

Complexos *cria_nro(float a, float b)
{
  Complexos *num = (Complexos *)malloc(sizeof(Complexos));
  if (!num)
    return 0;
  num->real = a;
  num->imaginario = b;
  return num;
}

void libera_nro(Complexos *num)
{
  free(num);
  num = NULL;
}
Complexos *soma(Complexos *x, Complexos *y)
{
  Complexos *result = cria_nro((float)(x->real + y->real), (float)(x->imaginario + y->imaginario));
  return result;
}
Complexos *subtracao(Complexos *x, Complexos *y)
{
  Complexos *result = cria_nro((float)(x->real - y->real), (float)(x->imaginario - y->imaginario));
  return result;
}
Complexos *mult(Complexos *x, Complexos *y)
{
  float ac = (float)(x->real * y->real);
  float bd = (float)(x->imaginario * y->imaginario);

  float ad = (float)(x->real * y->imaginario);
  float bc = (float)(x->imaginario * y->real);
  Complexos *result = cria_nro((ac - bd), (ad + bc));
  return result;
}

void get_value(Complexos *x, float *real, float *imaginary)
{
  if (!x)
    exit(0);
  *imaginary = x->imaginario;
  *real = x->real;
}