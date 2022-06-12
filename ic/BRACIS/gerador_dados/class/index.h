#include "./../utils/index.h"
#define R 3
#define C 3
class Celula
{
private:
    var estado, tempo_desde_queima, tempo_queimando;
    static int coef;
    static double **matrixCoef;

    static double decaimento, mult_base;

    double **create_MatrixCoef(int m, int n);
    void set_estado(var estado);
    void avanca_fogo();
    float influencia_vegetacao(var estado_atual_vegetacao);

public:
    Celula(var estado, int coef);
    Celula();
    var get_estado();
    void heitorzeira2(Celula n, Celula s, Celula o, Celula l, Celula ne, Celula no, Celula se, Celula so);
};

void print_reticulado(Celula reticulado[TAMANHO_RETICULADO + 1][TAMANHO_RETICULADO + 1]);