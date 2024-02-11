#include "reticulado.h"
// [0,1]
typedef float Probabilidade;
typedef unsigned short *TempoNoEstado;
typedef Estado *MapaTransicao;
typedef bool **MatrizQueima;

typedef struct
{
  Probabilidade passar_fogo_da_superficie_para_vegetacao;
  Probabilidade passar_fogo_da_vegetacao_para_superficie;

  DirecaoVento direcao_vento;

  Estado transicoes[QUANTIDADE_ESTADOS];

  Probabilidade vegetacao_pegar_fogo[QUANTIDADE_ESTADOS];
  Probabilidade fogo_espalhar[QUANTIDADE_ESTADOS];

  // -1 indica infinito, como a água que não transiciona,
  // e vegetação que a transição não depende de tempo
  TempoNoEstado tempo_no_estado[QUANTIDADE_ESTADOS];

} ParametrosModelo;

// Retorna o novo estado da célula
Estado atualiza_celula(
    Celula *c,
    Vizinhanca v,
    Experimento *e,
    ParametrosModelo p,
    unsigned short nivel,
    Probabilidade **matriz_probs_aleatorias,
    Probabilidade influencia_umidade);

void run_experimento(Experimento *e, ParametrosModelo p);
void define_transicoes(MapaTransicao *m); // TODO: Rodar ao criar o modelo

MatrizQueima onde_esta_queimando(Vizinhanca v, Estado estado_fogo, unsigned short tamanho_vizinhanca, unsigned short nivel);
unsigned short quantidade_queimando(MatrizQueima m, unsigned short tamanho_vizinhanca, unsigned short nivel);

void get_matriz_probabilidade(Probabilidade **prob, unsigned short tamanho_vizinhanca);
