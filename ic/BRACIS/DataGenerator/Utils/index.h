//
// Created by heito on 10/06/2022.
//

#ifndef DATAGENERATOR_INDEX_H
#define DATAGENERATOR_INDEX_H
#include <string>
#define R 3
#define C 3
#define TAMANHO_RETICULADO 512
#define qnt_estados 8
#define HORIZONTAL 1024
#define VERTICAL 1024
#define t_inicio_fogo 3
#define t_arvore_queimando 17
#define solo_exposto 0
#define inicio_fogo 1
#define arvore_queimando 2
#define queima_lenta 3
#define campestre 4
#define savanica 5
#define florestal 6
#define agua 7
typedef short int var;

void set_vento(std::string, std::string f, float *matrixCoef);


float random_range(int i, int f);
float random_range(int f);
float random_range();

#endif //DATAGENERATOR_INDEX_H
