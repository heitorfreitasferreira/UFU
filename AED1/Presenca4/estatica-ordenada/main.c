#include "lista.h"
#include <stdio.h>
int main(int argc, char const *argv[])
{
  //INICIALIZA A LISTA
  Lista lst = cria_lista();
  //IMPRIME A LISTA
  for (size_t i = 0; i < get_size(lst); i++)
    printf("%.2f ", get_posicao(lst, i));
  printf("\n");
  //INSIRA OS ELEMENTOS NA ORDEM
  float aux[10] = {4, 8.5, -1.1, 19, 2.5, 7, 8.45, -9, 22, 45.7};
  for (size_t i = 0; i < 10; i++)
    insere_elem(lst, aux[i]);
  //IMPRIME A LISTA
  for (size_t i = 0; i < get_size(lst); i++)
    printf("%.2f ", get_posicao(lst, i));
  printf("\n");
  //REMOVA O ELEMENTO 7
  remove_elem(lst, 7);
  //IMPRIME A LISTA
  for (size_t i = 0; i < get_size(lst); i++)
    printf("%.2f ", get_posicao(lst, i));
  printf("\n");
  //REMOVA O ELEMENTO 8.55
  remove_elem(lst, 8.55);
  //IMPRIME A LISTA
  for (size_t i = 0; i < get_size(lst); i++)
    printf("%.2f ", get_posicao(lst, i));
  printf("\n");
  //LIMPA A LISTA
  limpa_lista(lst);
  //IMPRIME A LISTA
  for (size_t i = 0; i < get_size(lst); i++)
    printf("%.2f ", get_posicao(lst, i));
  printf("\n");
  return 0;
}
