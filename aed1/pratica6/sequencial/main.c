#include <stdio.h>
#include "lista.h"
#define tam 11
int main(int argc, char const *argv[])
{
  Lista lst = cria_lista();
  int tmp, i = 0;
  while (obtem_valor_elem(&lst, i, &tmp))
  {
    printf("%d\t", tmp);
    i++;
  }

  printf("\n\n");
  // INSERINDO
  int aux[tam] = {4, 8, -1, 19, 2, 7, 8, 5, 9, 22, 45};
  for (size_t i = 0; i < tam; i++)
    insere_elem(&lst, aux[i]);
  // IMPRIMINDO LISTA
  i = 0;
  while (obtem_valor_elem(&lst, i, &tmp))
  {
    printf("%d\t", tmp);
    i++;
  }

  printf("\n\n");
  // REMOVENDO ELEMENTO 8
  remove_elem(&lst, 8);

  // IMPRIMINDO LISTA
  i = 0;
  while (obtem_valor_elem(&lst, i, &tmp))
  {
    printf("%d\t", tmp);
    i++;
  }

  printf("\n\n");
  return 0;
}
