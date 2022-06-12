//
// Created by heito on 10/06/2022.
//

#ifndef DATAGENERATOR_CELULA_H
#define DATAGENERATOR_CELULA_H

#include "./../Utils/index.h"
class Celula
{
private:
    var estado, tempo_desde_queima, tempo_queimando;
     int coef;
     double **matrixCoef;

     double decaimento, mult_base;

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


#endif //DATAGENERATOR_CELULA_H
