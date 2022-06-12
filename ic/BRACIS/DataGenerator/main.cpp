#include <iostream>
#include <array>
#include "./Class/Celula.h"

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

void print_vizinhanca(double mat[3][3], int m = 3, int n = 3)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << mat[i][j] << " ";
        std::cout << std::endl;
    }
}
//char mapeiaIcone[10];


template<class T, size_t rows, size_t cols>
class Matrix
{
    std::array<T, rows * cols> m_Data;
public:
    T& operator()(size_t y, size_t x)
    {
        return m_Data[y * cols + x];
    }

    // more methods go here
};
int main() {
//    Celula reticulado[TAMANHO_RETICULADO + 1][TAMANHO_RETICULADO + 1] = Celula(), aux_reticulado[TAMANHO_RETICULADO][TAMANHO_RETICULADO] = Celula();
    Celula c;
    //std::array<std::array<Celula, TAMANHO_RETICULADO>, TAMANHO_RETICULADO> reticulado;
    //std::array<std::array<Celula, TAMANHO_RETICULADO>, TAMANHO_RETICULADO> aux_reticulado;

    Matrix<Celula, TAMANHO_RETICULADO, TAMANHO_RETICULADO> arr;
    std::cout<<"Deu bom"<<std::endl;


    return 0;
}
