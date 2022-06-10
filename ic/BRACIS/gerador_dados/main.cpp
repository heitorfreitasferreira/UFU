#include <iostream>
#include <time.h>
#include "./utils/index.h"
#include "./class/index.h"
const var umidade = 0;
float coef = 1;
double matrixCoef[3][3] =
    {
        {coef * 0.12, coef * 0.16, coef * 0.12},
        {coef * 0.08, 0, coef * 0.08},
        {coef * 0.04, coef * 0.002, coef * 0.04}
    };


#pragma endregion Macros
using namespace std;

Celula reticulado[TAMANHO_RETICULADO + 1][TAMANHO_RETICULADO + 1], aux_reticulado[TAMANHO_RETICULADO][TAMANHO_RETICULADO];

int main(int argc, char const *argv[])
{
    
    srand(time(NULL));
    random_range();

    #pragma region Inicializando reticulados
    Celula reticulado[TAMANHO_RETICULADO][TAMANHO_RETICULADO];
    print_reticulado(reticulado);
    
    #pragma endregion
    return 0;
}
