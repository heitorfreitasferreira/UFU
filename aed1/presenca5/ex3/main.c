#include <stdio.h>
#include "lista.h"
#define tam 11
int main(int argc, char const *argv[])
{
  Lista lst = cria_lista();
  int tmp, i = 0;
  int aux[tam] = {4, 8, -1, 19, 2, 7, 8, 5, 9, 22, 45};
  if (!obtem_valor_elem(&lst, i, &tmp))
  {
    printf("Lista vazia, nao ha elementos para mostrar\n");
  }
  else
  {
    while (obtem_valor_elem(&lst, i, &tmp))
    {
      printf("%d\t", tmp);
      i++;
    }

    printf("\n\n");
  }
  // INSERINDO
  for (size_t i = 0; i < tam; i++)
    insere_final(&lst, aux[i]);
  // IMPRIMINDO LISTA
  i = 0;
  if (!obtem_valor_elem(&lst, i, &tmp))
  {
    printf("Lista vazia, nao ha elementos para mostrar\n");
  }
  else
  {
    while (obtem_valor_elem(&lst, i, &tmp))
    {
      printf("%d\t", tmp);
      i++;
    }

    printf("\n\n");
  }
  // REMOVENDO PRIMEIRO ELEMENTO
  remove_inicio(&lst, &tmp);
  printf("Elemento removido: %d\n\n", tmp);

  // IMPRIMINDO LISTA
  i = 0;
  if (!obtem_valor_elem(&lst, i, &tmp))
  {
    printf("Lista vazia, nao ha elementos para mostrar\n");
  }
  else
  {
    while (obtem_valor_elem(&lst, i, &tmp))
    {
      printf("%d\t", tmp);
      i++;
    }

    printf("\n\n");
  }
  return 0;
}
