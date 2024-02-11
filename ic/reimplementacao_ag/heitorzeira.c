#include "modelo.h"
// #include "reticulado.h"
// #include "celula.h"

typedef unsigned short size_t;

Estado atualiza_celula(
    Celula *c,
    Vizinhanca v,
    Experimento *e,
    ParametrosModelo p,
    unsigned short nivel,
    Probabilidade **matriz_probs_aleatorias,
    Probabilidade influencia_umidade)
{

  unsigned short tamanho_vizinhanca = e->reticulado.tamanho_vizinhanca;

  if (celula_esta_em_chamas(c))
  {
    if (c->tempo_no_estado > p.tempo_no_estado[get_estado_index(c)])
      return p.transicoes[get_estado_index(c)];

    if (celula_eh_passivel_de_queimar(c, v, tamanho_vizinhanca, nivel))
    {
      Probabilidade INFLUENCIA_RELEVO = 1.0;
      get_matriz_probabilidade(matriz_probs_aleatorias, tamanho_vizinhanca);
      for (size_t i = 0; i < tamanho_vizinhanca; i++)
      {
        for (size_t j = 0; j < tamanho_vizinhanca; j++)
        {
          // Se estiver na celula do meio, pular iteração
          if (i == tamanho_vizinhanca / 2 && j == tamanho_vizinhanca / 2)
            continue;

          Probabilidade transicao =
              e->reticulado.vento[i][j] *
              p.fogo_espalhar[get_estado_index(c)] *
              p.vegetacao_pegar_fogo[get_estado_numeric(v[i][j])] *
              influencia_umidade * INFLUENCIA_RELEVO;

          if (matriz_probs_aleatorias[i][j] <= transicao)
          {
            return p.transicoes[get_estado_index(c)];
          }
        }
      }
    }

    return c->estado;
  }
}

bool celula_eh_passivel_de_queimar(Celula *c, Vizinhanca v, unsigned short tamanho_vizinhanca, unsigned short nivel)
{
  if (celula_eh_vegetacao(c))
  {
    MatrizQueima matriz_queima = onde_esta_queimando(v, FOG_INICIAL, tamanho_vizinhanca, nivel);
    unsigned short quantidade = quantidade_queimando(matriz_queima, tamanho_vizinhanca, nivel);
    if (quantidade > 0)
    {
      return true;
    }
  }
  return false;
}

void run_experimento(Experimento *e, ParametrosModelo p)
{
  // Allocate Vizinhaça
  Vizinhanca vizinhanca = (Vizinhanca)malloc(e->reticulado.tamanho_vizinhanca * sizeof(Vizinhanca));
  for (unsigned short i = 0; i < e->reticulado.tamanho_vizinhanca; i++)
    vizinhanca[i] = (Estado *)malloc(e->reticulado.tamanho_vizinhanca * sizeof(Estado));
  // Allocate the probability matrix
  Probabilidade **matriz_probs_aleatorias = (Probabilidade **)malloc(e->reticulado.tamanho_vizinhanca * sizeof(Probabilidade *));
  for (unsigned short i = 0; i < e->reticulado.tamanho_vizinhanca; i++)
    matriz_probs_aleatorias[i] = (Probabilidade *)malloc(e->reticulado.tamanho_vizinhanca * sizeof(Probabilidade));

  inicializa_tempo_no_estado(p.tempo_no_estado, e->reticulado.umidade, e->tresholds_umidade);
  Probabilidade influencia_umidade = calcula_influencia_umidade(*e);

  for (size_t i = 0; i < QUANTIDADE_EXPERIMENTOS; i++)
  {
    for (size_t j = 0; j < QUANTIDADE_ITERACOES; j++)
    {
      e->reticulado.tempo = j;
      iteracao(e, p, vizinhanca, matriz_probs_aleatorias, influencia_umidade);
      rio_de_fogo(e, p, vizinhanca, matriz_probs_aleatorias, influencia_umidade);

      // Salva no buffer
      salva_no_buffer(e, i);
    }
  }

  // Free the allocated memory
  for (unsigned short i = 0; i < e->reticulado.tamanho_vizinhanca; i++)
  {
    free(vizinhanca[i]);
    free(matriz_probs_aleatorias[i]);
  }
  free(vizinhanca);
  free(matriz_probs_aleatorias);
}

void salva_no_buffer(Experimento *exp, size_t nro_experimento)
{
  for (size_t i = 0; i < ALTURA; i++)
  {
    for (size_t j = 0; j < LARGURA; j++)
    {
      for (size_t nivel = 0; nivel < NIVEIS; nivel++)
      {
        exp->output[nro_experimento][exp->reticulado.tempo][i][j][nivel] = exp->reticulado.celulas[i][j][nivel].estado;
      }
    }
  }
}

void iteracao(Experimento *e, ParametrosModelo p, Vizinhanca vizinhanca, Probabilidade **matriz_probs_aleatorias, Probabilidade influencia_umidade)
{
  for (size_t i = 0; i < ALTURA; i++)
  {
    for (size_t j = 0; j < LARGURA; j++)
    {
      for (size_t nivel = 0; nivel < NIVEIS; nivel++)
      {
        get_vizinhanca(vizinhanca, &e->reticulado, i, j, nivel);
        Estado novo_estado = atualiza_celula(
            &e->reticulado.celulas[i][j][nivel],
            vizinhanca,
            e,
            p,
            nivel,
            matriz_probs_aleatorias,
            influencia_umidade);

        avanca_tempo(&e->reticulado.celulas[i][j][nivel], novo_estado);
      }
    }
  }
}

void rio_de_fogo(Experimento *e, ParametrosModelo p, Vizinhanca vizinhanca, Probabilidade **matriz_probs_aleatorias, Probabilidade influencia_umidade)
{
  for (size_t i = 0; i < ALTURA; i++)
  {
    for (size_t j = 0; j < LARGURA; j++)
    {
      bool superficie_pegando_fogo = celula_esta_em_chamas(&e->reticulado.celulas[i][j][SUPERFICIE_IDX]);
      bool subterraneo_pegando_fogo = celula_esta_em_chamas(&e->reticulado.celulas[i][j][SUBTERRANEO_IDX]);

      if ((superficie_pegando_fogo && !subterraneo_pegando_fogo) && rand() < p.passar_fogo_da_superficie_para_vegetacao)
        avanca_tempo(&e->reticulado.celulas[i][j][SUBTERRANEO_IDX], FOG_INICIAL);
      if ((!superficie_pegando_fogo && subterraneo_pegando_fogo) && rand() < p.passar_fogo_da_vegetacao_para_superficie)
        avanca_tempo(&e->reticulado.celulas[i][j][SUPERFICIE_IDX], FOG_INICIAL);
    }
  }
}
void get_vizinhanca(Vizinhanca vizinhanca, Reticulado *r, size_t i, size_t j, size_t nivel)
{
  unsigned short tamanho_vizinhanca = r->tamanho_vizinhanca;

  int halfSize = tamanho_vizinhanca / 2;
  for (int di = -halfSize; di <= halfSize; di++)
  {
    for (int dj = -halfSize; dj <= halfSize; dj++)
    {
      int neighborI = i + di;
      int neighborJ = j + dj;

      vizinhanca[di + halfSize][dj + halfSize] =
          (neighborI < 0 || neighborI >= ALTURA || neighborJ < 0 || neighborJ >= LARGURA)
              ? AGUA
              : r->celulas[neighborI][neighborJ][nivel].estado;
    }
  }
}

MatrizQueima onde_esta_queimando(Vizinhanca v, Estado estado_fogo, unsigned short tamanho_vizinhanca, unsigned short nivel)
{
  MatrizQueima matriz_queima = (MatrizQueima)malloc(tamanho_vizinhanca * sizeof(MatrizQueima));
  for (unsigned short i = 0; i < tamanho_vizinhanca; i++)
  {
    matriz_queima[i] = (bool *)malloc(tamanho_vizinhanca * sizeof(bool));
  }
  for (unsigned short i = 0; i < tamanho_vizinhanca; i++)
  {
    for (unsigned short j = 0; j < tamanho_vizinhanca; j++)
    {
      if (eh_estado_de_fogo(v[i][j]))
      {
        matriz_queima[i][j] = true;
      }
      else
      {
        matriz_queima[i][j] = false;
      }
    }
  }
  return matriz_queima;
}

unsigned short quantidade_queimando(MatrizQueima m, unsigned short tamanho_vizinhanca, unsigned short nivel)
{
  unsigned short quantidade = 0;
  for (unsigned short i = 0; i < tamanho_vizinhanca; i++)
  {
    for (unsigned short j = 0; j < tamanho_vizinhanca; j++)
    {
      if (m[i][j])
      {
        quantidade++;
      }
    }
  }
  return quantidade;
}

void get_matriz_probabilidade(Probabilidade **prob, unsigned short tamanho_vizinhanca)
{
  for (unsigned short i = 0; i < tamanho_vizinhanca; i++)
  {
    for (unsigned short j = 0; j < tamanho_vizinhanca; j++)
    {
      prob[i][j] = rand(); // Assigning a random number to the variable
    }
  }
}

void inicializa_tempo_no_estado(TempoNoEstado *tempo_no_estado, Probabilidade umidade, Tresholds tresholds_umidade)
{
  TempoNoEstado *tempo_no_estado = (TempoNoEstado *)malloc(QUANTIDADE_ESTADOS * sizeof(TempoNoEstado));
  tempo_no_estado[AGUA_IDX] = -1;
  tempo_no_estado[VEG_CAMPESTRE_IDX] = -1;
  tempo_no_estado[VEG_SAVANICA_IDX] = -1;
  tempo_no_estado[VEG_FLORESTA_IDX] = -1;
  tempo_no_estado[RAIZ_IDX] = -1;
  tempo_no_estado[TERRA_IDX] = -1;
  tempo_no_estado[SUBTERRANEO_IDX] = -1;
  if (umidade <= tresholds_umidade.treshold1)
  {
    tempo_no_estado[FOG_INICIAL_IDX] = 3;
    tempo_no_estado[FOG_ESTAVEL_IDX] = 8;
    tempo_no_estado[FOG_BRAZA_IDX] = 7;
  }
  else
  {
    tempo_no_estado[FOG_INICIAL_IDX] = -3;
    tempo_no_estado[FOG_ESTAVEL_IDX] = 3;
    tempo_no_estado[FOG_BRAZA_IDX] = 10;
  }
}

Probabilidade calcula_influencia_umidade(Experimento exp)
{
  Probabilidade umidade = exp.reticulado.umidade;
  Tresholds tresholds = exp.tresholds_umidade;

  if (umidade > 0.0 && umidade <= tresholds.treshold1)
    return 1.5;
  else if (umidade > tresholds.treshold1 && umidade <= tresholds.treshold2)
    return 1.0;
  else if (umidade > tresholds.treshold2 && umidade <= tresholds.treshold3)
    return 0.8;
  else if (umidade > tresholds.treshold3 && umidade <= tresholds.treshold4)
    return 0.6;

  else
    return -1;
}