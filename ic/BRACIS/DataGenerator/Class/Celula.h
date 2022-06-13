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
     int t_inicio_fogo;
     int t_arvore_queimando;
     int t_queima_lenta;
     double coef_umidade,umidade;
     double **matrixCoef;
     double decaimento, mult_base;

    double **create_MatrixCoef(int m, int n);
    void avanca_fogo();
    float influencia_vegetacao(var estado_atual_vegetacao);
    Celula* clone()const;
    void influencia_umidade(double umidade);
//    Celula& operator=(const Celula& rhs);

public:
    Celula(var estado, int coef,double umidade);
    void set_estado(var estado);
    Celula(const Celula &rhs);
    Celula();
    var get_estado();
    Celula heitorzeira2(Celula n, Celula s, Celula o, Celula l, Celula ne, Celula no, Celula se, Celula so);
};


#endif //DATAGENERATOR_CELULA_H
