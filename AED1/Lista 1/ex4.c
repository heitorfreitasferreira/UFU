#include <stdio.h>
unsigned long long int fat(int x)
{
  if (x == 1 || x == 0)
    return 1;
  else if (x < 0)
    return -1;
  else
    return (x * fat(x - 1));
}
int combinatoria(int m, int p)
{
  if (p > m)
    return -1;
  else
    return (fat(m) / (fat(p) * fat(m - p)));
}
int main(int argc, char const *argv[])
{
  int m, p;
  printf("M=");
  scanf("%d", &m);
  printf("P=");
  scanf("%d", &p);
  printf("%d\n", combinatoria(m, p));
}
