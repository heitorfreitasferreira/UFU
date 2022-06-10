#include "index.h"
#include <iostream>

void print_reticulado(Celula reticulado[TAMANHO_RETICULADO][TAMANHO_RETICULADO])
{
    var mapeiaIcone[10];
    mapeiaIcone[solo_exposto] = '.';
    mapeiaIcone[inicio_fogo] = '*';
    mapeiaIcone[arvore_queimando] = '#';
    mapeiaIcone[queima_lenta] = 'o';
    mapeiaIcone[campestre] = '_';
    mapeiaIcone[savanica] = '-';
    mapeiaIcone[florestal] = 'T';

    for (int i = 0; i < TAMANHO_RETICULADO; i++)
    {
        for (int j = 0; j < TAMANHO_RETICULADO; j++)
            printf("%c ", mapeiaIcone[reticulado[i][j].get_estado()]);
        std::cout << std::endl;
    }
}