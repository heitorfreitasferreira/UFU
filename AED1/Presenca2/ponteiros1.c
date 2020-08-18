#include <stdio.h>
int main(int argc, char const *argv[])
{
  double *p, *q, *r, A[5] = {0, 1, 2, 3, 4};
  p = A;
  q = p + 1;
  r = q + 2;                                      //CONSIDERANDO A[0] = 1234600
  printf("&A[0] = %lu; *r = %lf;\n", &A[0], *r);  //&A[0] = 1234600; *r = 3.000000;
  printf("p = %lu; *(A+1) = %lf\n", p, *(A + 1)); //p = 1234600; *(A+1) = 1.000000
  r = p + 4;
  p = q;
  printf("p+1 = %lu; *(r-2) = %lf\n", p + 1, *(r - 2)); //p+1 = 1234616; *(r-2) = 2.000000
  printf("&A[4] = %lu; *r = %lf\n", &A[4], *r);         //&A[4] = 1234632; *r = 4.000000
  return 0;
}
