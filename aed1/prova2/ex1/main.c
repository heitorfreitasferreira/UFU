#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main(int argc, char const *argv[])
{
  StaticStack frase = create_stack();
  char entrada[max], aux;
  int i = 0, j = 0;
  scanf("%[^\n]", entrada);
  while (entrada[i] != '\0' || i > max)
  {
    push(frase, entrada[i]);
    i++;
  }
  while (i--)
  {
    pop(frase, &aux);
    if (aux != entrada[j])
      break;
    j++;
  }
  if (i > 0)
    printf("Nao e palindromo\n");
  else
    printf("Eh palindromo\n");

  return 0;
}
