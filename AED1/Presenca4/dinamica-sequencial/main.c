#include <stdio.h>
#include "lista.h"
#define tam 9
int main(int argc, char const *argv[])
{
  //INICIALIZA A LISTA
  Lista lst = cria_lista();
  char x;
  //IMPRIME A LISTA
  if (!obtem_tamanho(&lst))
  {
    printf("Lista vazia\n");
  }
  else
  {
    for (size_t i = 0; i < obtem_tamanho(&lst); i++)
    {
      obtem_posicao(lst, i, &x);
      printf("%c ", x);
    }
    printf("\n");
  }

  //INSIRA OS ELEMENTOS NA ORDEM
  float aux[tam] = {'d', 'f', 'a', 'A', 'G', 'y', 'm', 'o', 'P'};
  for (size_t i = 0; i < tam; i++)
    insere_elem(&lst, aux[i]);

  // obtem_posicao(lst, 2, &x);
  // printf("%c\n", x);

  // printf("%d\n", obtem_tamanho(&lst));
  //IMPRIME A LISTA
  if (!obtem_tamanho(&lst))
  {
    printf("Lista vazia\n");
  }
  else
  {
    for (size_t i = 0; i < obtem_tamanho(&lst); i++)
    {
      obtem_posicao(lst, i, &x);
      printf("%c ", x);
    }
    printf("\n");
  }

  //REMOVA O 'M'
  if (!remove_elem(&lst, 'M'))
  {
    printf("Elemento nao existe\n");
  }
  //REMOVA O 'm'
  if (!remove_elem(&lst, 'm'))
  {
    printf("Elemento nao existe\n");
  }
  // IMPRIME A LISTA
  if (!obtem_tamanho(&lst))
  {
    printf("Lista vazia\n");
  }
  else
  {
    for (size_t i = 0; i < obtem_tamanho(&lst); i++)
    {
      obtem_posicao(lst, i, &x);
      printf("%c ", x);
    }
    printf("\n");
  }

  //ESVAZIE A LISTA
  limpa_lista(&lst);
  // IMPRIME A LISTA
  if (!obtem_tamanho(&lst))
  {
    printf("Lista vazia\n");
  }
  else
  {
    for (size_t i = 0; i < obtem_tamanho(&lst); i++)
    {
      obtem_posicao(lst, i, &x);
      printf("%c ", x);
    }
    printf("\n");
  }
  return 0;
}
