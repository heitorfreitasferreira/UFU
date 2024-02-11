#include "vento.h"

void rotate(MatrizVento matrizVento)
{
  int size = 3;
  int row = 0, col = 0;
  int m = size, n = size;
  double prev, curr;

  /*
  row - Starting row index
  m - ending row index
  col - starting column index
  n - ending column index
  i - iterator
  */
  while (row < m && col < n)
  {

    if (row + 1 == m || col + 1 == n)
      break;

    // Store the first element of next row, this
    // element will replace first element of current
    // row
    prev = matrizVento[row + 1][col];

    /* Move elements of first row from the remaining rows */
    for (int i = col; i < n; i++)
    {
      curr = matrizVento[row][i];
      matrizVento[row][i] = prev;
      prev = curr;
    }
    row++;

    /* Move elements of last column from the remaining columns */
    for (int i = row; i < m; i++)
    {
      curr = matrizVento[i][n - 1];
      matrizVento[i][n - 1] = prev;
      prev = curr;
    }
    n--;

    /* Move elements of last row from the remaining rows */
    if (row < m)
    {
      for (int i = n - 1; i >= col; i--)
      {
        curr = matrizVento[m - 1][i];
        matrizVento[m - 1][i] = prev;
        prev = curr;
      }
    }
    m--;

    /* Move elements of first column from the remaining rows */
    if (col < n)
    {
      for (int i = m - 1; i >= row; i--)
      {
        curr = matrizVento[i][col];
        matrizVento[i][col] = prev;
        prev = curr;
      }
    }
    col++;
  }
}

void rotate(MatrizVento matrizVento, int vezes)
{
  for (int i = 0; i < vezes; i++)
  {
    rotate(matrizVento);
  }
}

MatrizVento criaMatrizVento(int size, double coef, double mult_base, double decai, DirecaoVento direcao)
{
  size = 3; // TODO: Aumentar para 7 para faísca
  MatrizVento matrizVento = (MatrizVento)malloc(size * sizeof(MatrizVento));
  for (int i = 0; i < size; i++)
  {
    matrizVento[i] = (double *)malloc(size * sizeof(double));
  }
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      matrizVento[i][j] = 0;
    }
  }
  matrizVento[1][1] = 0;
  matrizVento[0][0] = coef * (mult_base - (decai * 1));
  matrizVento[0][1] = coef * (mult_base - (decai * 0));
  matrizVento[0][2] = coef * (mult_base - (decai * 1));
  matrizVento[1][0] = coef * (mult_base - (decai * 2));
  matrizVento[1][2] = coef * (mult_base - (decai * 2));
  matrizVento[2][0] = coef * (mult_base - (decai * 3));
  matrizVento[2][1] = coef * (mult_base - (decai * 4));
  matrizVento[2][2] = coef * (mult_base - (decai * 3));
  // if (direcao == S)
  // {
  // }
  if (direcao == SO)
    rotate(1);
  else if (direcao == O)
    rotate(2);
  else if (direcao == NO)
    rotate(3);
  else if (direcao == N)
    rotate(4);
  else if (direcao == NE)
    rotate(5);
  else if (direcao == E)
    rotate(6);
  else if (direcao == SE)
    rotate(7);
  return matrizVento;
}
