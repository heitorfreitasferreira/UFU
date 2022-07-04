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

double **Celula::create_MatrixCoef(int m, int n)
{
    double **matrix;
    matrix = new double *[m];
    for (int i = 0; i < m; i++)
        matrix[i] = new double[n];

    matrix[1][1] = 0;
    matrix[0][0] = this->coef * (this->mult_base - (this->decaimento * 1));
    matrix[0][1] = this->coef * (this->mult_base - (this->decaimento * 0));
    matrix[0][2] = this->coef * (this->mult_base - (this->decaimento * 1));
    matrix[1][0] = this->coef * (this->mult_base - (this->decaimento * 2));
    matrix[1][2] = this->coef * (this->mult_base - (this->decaimento * 2));
    matrix[2][0] = this->coef * (this->mult_base - (this->decaimento * 3));
    matrix[2][1] = this->coef * (this->mult_base - (this->decaimento * 4));
    matrix[2][2] = this->coef * (this->mult_base - (this->decaimento * 3));

    return matrix;
}
void Celula::set_estado(var estado)
{
    this->estado = estado;
    if (estado == solo_exposto)
    {
        tempo_desde_queima = 0;
        tempo_queimando = 0;
    }
    else
        tempo_desde_queima = -1;
    // ---------
    if (estado == arvore_queimando)
        tempo_queimando = t_inicio_fogo;
    else if (estado == queima_lenta)
        tempo_queimando = t_arvore_queimando;
    else
        tempo_queimando = 0;
}
void Celula::avanca_fogo()
{
    tempo_queimando++;
    if (tempo_queimando >= t_inicio_fogo)
    {
        set_estado(arvore_queimando);
        return;
    }
    if (tempo_queimando >= t_arvore_queimando)
    {
        set_estado(queima_lenta);
        return;
    }
    if (tempo_queimando > 16)
    {
        set_estado(solo_exposto);
        return;
    }
}
float Celula::influencia_vegetacao(var estado_atual_vegetacao)
{
    if (estado_atual_vegetacao == savanica)
        return 1;
    if (estado_atual_vegetacao == florestal)
        return 0.8;
    if (estado_atual_vegetacao == campestre)
        return 0.6;
    return -1;
}

Celula::Celula(var estado, int coef)
{
    this->coef = coef;
    set_estado(estado);
    decaimento = 0.04; // Padrão ACRI = 0.04
    mult_base = 0.16;
    coef = 1;
    matrixCoef = create_MatrixCoef(R, C);
}
Celula::Celula()
{
    // set_estado(campestre);

    // decaimento = 0.04; // Padrão ACRI = 0.04

    // mult_base = 0.16;
    // coef = 1;
    // matrixCoef = create_MatrixCoef(R, C);
}
var Celula::get_estado()
{
    return this->estado;
}

// _____________________________________________
void Celula::heitorzeira2(Celula n, Celula s, Celula o, Celula l, Celula ne, Celula no, Celula se, Celula so)
{
    bool temQueima[3][3] = {
        {no.estado == arvore_queimando, n.estado == arvore_queimando, ne.estado == arvore_queimando},
        {o.estado == arvore_queimando, false, l.estado == arvore_queimando},
        {so.estado == arvore_queimando, s.estado == arvore_queimando, se.estado == arvore_queimando}};
    bool temInicioFogo[3][3] = {
        {no.estado == inicio_fogo, n.estado == inicio_fogo, ne.estado == inicio_fogo},
        {o.estado == inicio_fogo, false, l.estado == inicio_fogo},
        {so.estado == inicio_fogo, s.estado == inicio_fogo, se.estado == inicio_fogo}}; // 0.6
    bool temBrasa[3][3] = {
        {no.estado == queima_lenta, n.estado == queima_lenta, ne.estado == queima_lenta},
        {o.estado == queima_lenta, false, l.estado == queima_lenta},
        {so.estado == queima_lenta, s.estado == queima_lenta, se.estado == queima_lenta}}; // 0.2
    var temQueimaSoma = temQueima[0][0] + temQueima[0][1] + temQueima[0][2] + temQueima[1][0] + temQueima[1][1] + temQueima[1][2] + temQueima[2][0] + temQueima[2][1] + temQueima[2][1];
    var temInicioFogoSoma = temInicioFogo[0][0] + temInicioFogo[0][1] + temInicioFogo[0][2] + temInicioFogo[1][0] + temInicioFogo[1][1] + temInicioFogo[1][2] + temInicioFogo[2][0] + temInicioFogo[2][1] + temInicioFogo[2][1];
    var temBrasaSoma = temBrasa[0][0] + temBrasa[0][1] + temBrasa[0][2] + temBrasa[1][0] + temBrasa[1][1] + temBrasa[1][2] + temBrasa[2][0] + temBrasa[2][1] + temBrasa[2][1];

    if (estado >= inicio_fogo && estado <= queima_lenta)
        tempo_queimando++;
    if (estado == solo_exposto)
        tempo_desde_queima++;
    if (estado == inicio_fogo && tempo_queimando > 2)
        set_estado(arvore_queimando);
    if (estado == arvore_queimando && tempo_queimando > 6)
        set_estado(queima_lenta);
    if (estado == queima_lenta && tempo_queimando > 16)
        set_estado(solo_exposto);

    if (estado >= campestre && estado <= florestal && temQueimaSoma + temInicioFogoSoma + temBrasaSoma > 0)
    {

        double randomM[3][3] = {
            {random_range(0, 1), random_range(0, 1), random_range(0, 1)},
            {random_range(0, 1), 0, random_range(0, 1)},
            {random_range(0, 1), random_range(0, 1), random_range(0, 1)}};
        for (var i = 0; i < 3; i++)
        {
            for (var j = 0; j < 3; j++)
            {
                if (temInicioFogo[i][j] && randomM[i][j] < (matrixCoef[i][j] * 0.6 * influencia_vegetacao(estado)) /*-umidade_ar*/)
                    set_estado(inicio_fogo);
                if (temQueima[i][j] && randomM[i][j] < (matrixCoef[i][j] * influencia_vegetacao(estado)) /*-umidade_ar*/)
                    set_estado(inicio_fogo);
                if (temBrasa[i][j] && randomM[i][j] < (matrixCoef[i][j] * 0.2 * influencia_vegetacao(estado)) /*-umidade_ar*/)
                    set_estado(inicio_fogo);
            }
        }
    }
}