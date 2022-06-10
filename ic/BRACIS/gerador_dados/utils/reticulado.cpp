#include "index.h"
#include <iostream>
using namespace std;
void rotatematrix(double mat[R][C], int m = 3, int n = 3)
{
    int row = 0, col = 0;
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
        prev = mat[row + 1][col];

        /* Move elements of first row from the remaining rows */
        for (int i = col; i < n; i++)
        {
            curr = mat[row][i];
            mat[row][i] = prev;
            prev = curr;
        }
        row++;

        /* Move elements of last column from the remaining columns */
        for (int i = row; i < m; i++)
        {
            curr = mat[i][n - 1];
            mat[i][n - 1] = prev;
            prev = curr;
        }
        n--;

        /* Move elements of last row from the remaining rows */
        if (row < m)
        {
            for (int i = n - 1; i >= col; i--)
            {
                curr = mat[m - 1][i];
                mat[m - 1][i] = prev;
                prev = curr;
            }
        }
        m--;

        /* Move elements of first column from the remaining rows */
        if (col < n)
        {
            for (int i = m - 1; i >= row; i--)
            {
                curr = mat[i][col];
                mat[i][col] = prev;
                prev = curr;
            }
        }
        col++;
    }

    // Print rotated matrix
}
void set_vento(string i, string f, double matrixCoef[R][C])
{
    if (i == "n" && f == "s")
    {
    }
    else if (i == "ne" && f == "so")
    {
        rotatematrix(matrixCoef);
    }
    else if (i == "l" && f == "o")
    {
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
    }
    else if (i == "se" && f == "no")
    {

        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
    }
    else if (i == "s" && f == "n")
    {
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
    }
    else if (i == "so" && f == "ne")
    {
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
    }
    else if (i == "o" && f == "l")
    {
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
    }
    else if (i == "no" && f == "se")
    {
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
    }
}
void print_vizinhanca(double mat[3][3], int m = 3, int n = 3)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}
char mapeiaIcone[10];
