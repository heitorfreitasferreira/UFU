#include "celula.h"
#include "vento.h"

#define QUANTIDADE_EXPERIMENTOS 10
#define QUANTIDADE_ITERACOES 10
#define ALTURA 16
#define LARGURA 16
#define NIVEIS 2

#define SUBTERRANEO_IDX 1
#define SUPERFICIE_IDX 2

typedef struct
{
  Celula celulas[ALTURA][LARGURA][NIVEIS];
  const float umidade;
  // Deverá ter o mesmo tamanho da vizinhança
  MatrizVento vento;
  unsigned short tempo;
  const unsigned short tamanho_vizinhanca;
} Reticulado;

typedef struct
{
  Reticulado reticulado;
  Estado output[QUANTIDADE_EXPERIMENTOS][QUANTIDADE_ITERACOES][ALTURA][LARGURA][NIVEIS];
  const char *output_file_name;
  Tresholds tresholds_umidade;
} Experimento;

typedef struct
{
  const Probabilidade treshold1;
  const Probabilidade treshold2;
  const Probabilidade treshold3;
  const Probabilidade treshold4;
} Tresholds;

void inicializa_reticulado(
    Reticulado *r,
    MatrizVento v,
    unsigned short tamanho_matriz_vento,
    unsigned short **focos_iniciais_incendio,
    unsigned short quantidade_focos_iniciais_incendio,
    Estado **estado_inicial_superficie);

// void inicializa_matriz_vento(
//     MatrizVento *v,
//     unsigned short tamanho_matriz_vento,
//     double coef,
//     double mult_base,
//     double decai,
//     DirecaoVento direcao);
