#include <stdio.h>
#include "fila.h"
int elimina_elem(Fila *sala, int limite)
{
  if (fila_vazia(sala))
  {
    printf("Sala vazia, insira alunos antes\n ");
    return -1;
  }
  Fila sala_aux = cria_fila();
  int removidos = 0;
  Aluno aux;
  while (shift(sala, &aux))
  {
    if (aux.faltas <= limite)
      push(&sala_aux, aux);
    else
      removidos++;
  }
  if (removidos == 0)
  {
    printf("Nenhum aluno removido!\n");
    return removidos;
  }

  while (shift(&sala_aux, &aux))
    push(sala, aux);
  printf("%d alunos removidos da sala\n", removidos);
  return removidos;
}

int main(int argc, char const *argv[])
{
  Fila sala = cria_fila();

  return 0;
}
