#include <iostream>
#include <stdlib.h>
#include <vector>
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

using namespace std;

void print_reticulado(Celula *reticulado[TAMANHO_RETICULADO])
{
//    char mapeiaIcone[7];
//    mapeiaIcone[solo_exposto] = '.';
//    mapeiaIcone[inicio_fogo] = '*';
//    mapeiaIcone[arvore_queimando] = '#';
//    mapeiaIcone[queima_lenta] = 'o';
//    mapeiaIcone[campestre] = ';';
//    mapeiaIcone[savanica] = 'i';
//    mapeiaIcone[florestal] = '|';
    for (int i = 0; i < TAMANHO_RETICULADO; i++)
    {
        for (int j = 0; j < TAMANHO_RETICULADO; j++) {
            cout << reticulado[i][j].get_estado()<< " ";
        }
        cout << endl;
    }
    cout << endl;
}

using namespace std;
int main() {
    Celula** reticulado = (Celula**)malloc(sizeof(Celula*) * TAMANHO_RETICULADO+1);
    Celula** aux_reticulado = (Celula**)malloc(sizeof(Celula*) * TAMANHO_RETICULADO);
    // Alocação das matrizes
    for (int i = 0; i < TAMANHO_RETICULADO; ++i) {
        aux_reticulado[i] = (Celula*)malloc(sizeof(Celula) * TAMANHO_RETICULADO);
        for (int j = 0; j < TAMANHO_RETICULADO; ++j) {
            aux_reticulado[i][j] = Celula(campestre, 1, UMIDADE);
        }
    }
    for (int i = 0; i < TAMANHO_RETICULADO+1; ++i) {
        reticulado[i] = (Celula*)malloc(sizeof(Celula) * TAMANHO_RETICULADO+1);
        for (int j = 0; j < TAMANHO_RETICULADO; ++j) {
            if(i==TAMANHO_RETICULADO || j==TAMANHO_RETICULADO)
                reticulado[i][j] = Celula(solo_exposto,1,UMIDADE);
            else
                reticulado[i][j] = Celula(campestre,1,UMIDADE);
        }
    }


    reticulado[TAMANHO_RETICULADO/2][TAMANHO_RETICULADO/2].set_estado(arvore_queimando);
    aux_reticulado[TAMANHO_RETICULADO/2][TAMANHO_RETICULADO/2].set_estado(arvore_queimando);
    //    cout<<aux_reticulado[0][0].get_estado()<<endl;
    print_reticulado(reticulado);
    int iteracao = 0;
    do {
        for (int i = 0; i < TAMANHO_RETICULADO; ++i) {
            for (int j = 0; j < TAMANHO_RETICULADO; ++j) {
                int cima, baixo, esquerda, direita;
                if (i == 0)
                    cima = TAMANHO_RETICULADO;
                else
                    cima = i - 1;
                baixo = i + 1;
                if (j == 0)
                    esquerda = TAMANHO_RETICULADO;
                else
                    esquerda = j - 1;
                direita = j + 1;
                aux_reticulado[i][j] = reticulado[i][j].heitorzeira2(reticulado[cima][j],         // n
                                                                     reticulado[baixo][j],        // s
                                                                     reticulado[i][esquerda],     // o
                                                                     reticulado[i][direita],      // l
                                                                     reticulado[cima][direita],   // ne
                                                                     reticulado[cima][esquerda],  // no
                                                                     reticulado[baixo][direita],  // se
                                                                     reticulado[baixo][esquerda]    // centro
                );
            }
        }
        for (int i = 0; i < TAMANHO_RETICULADO; ++i) {
            for (int j = 0; j < TAMANHO_RETICULADO; ++j) {
                reticulado[i][j] = aux_reticulado[i][j];
            }
        }
        iteracao++;
        print_reticulado(reticulado);
    }while(iteracao<10);
    cout<<"rodou??"<<endl;
    return 0;
}
