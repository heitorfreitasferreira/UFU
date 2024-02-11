#include <stdio.h>
#include "modelo.h"

void escreve_buffer_em_arquivo_json(Experimento *exp)
{
  FILE *fp;
  fp = fopen(exp->output_file_name, "w");
  if (fp == NULL)
  {
    printf("Error opening file!\n");
    exit(1);
  }
  fprintf(fp, "{\n");
  fprintf(fp, "  \"experimentos\": [\n");
  for (size_t i = 0; i < QUANTIDADE_EXPERIMENTOS; i++)
  {
    fprintf(fp, "    {\n");
    fprintf(fp, "      \"iteracoes\": [\n");
    for (size_t j = 0; j < QUANTIDADE_ITERACOES; j++)
    {
      fprintf(fp, "        {\n");
      fprintf(fp, "          \"estado\": [\n");
      for (size_t k = 0; k < ALTURA; k++)
      {
        fprintf(fp, "            [");
        for (size_t l = 0; l < LARGURA; l++)
        {
          fprintf(fp, "              [");
          for (size_t m = 0; m < NIVEIS; m++)
          {
            fprintf(fp, "                %d", exp->output[i][j][k][l][m]);
            if (m < NIVEIS - 1)
            {
              fprintf(fp, ",");
            }
          }
          fprintf(fp, "              ]");
          if (l < LARGURA - 1)
          {
            fprintf(fp, ",");
          }
        }
        fprintf(fp, "            ]");
        if (k < ALTURA - 1)
        {
          fprintf(fp, ",");
        }
      }
      fprintf(fp, "          ]\n");
      fprintf(fp, "        }");
      if (j < QUANTIDADE_ITERACOES - 1)
      {
        fprintf(fp, ",");
      }
      fprintf(fp, "\n");
    }
    fprintf(fp, "      ]\n");
    fprintf(fp, "    }");
    if (i < QUANTIDADE_EXPERIMENTOS - 1)
    {
      fprintf(fp, ",");
    }
    fprintf(fp, "\n");
  }
  fprintf(fp, "  ]\n");
  fprintf(fp, "}\n");
  fclose(fp);
}

int main()
{
  ParametrosModelo params = {
      .passar_fogo_da_superficie_para_vegetacao = 0.5,
      .passar_fogo_da_vegetacao_para_superficie = 0.5,
      .direcao_vento = N};

  params.fogo_espalhar[VEG_CAMPESTRE_IDX] = 0.0;
  params.fogo_espalhar[VEG_SAVANICA_IDX] = 0.0;
  params.fogo_espalhar[VEG_FLORESTA_IDX] = 0.0;
  params.fogo_espalhar[RAIZ_IDX] = 0.0;
  params.fogo_espalhar[TERRA_IDX] = 0.0;
  params.fogo_espalhar[SUBTERRANEO_IDX] = 0.0;
  params.fogo_espalhar[FOG_INICIAL_IDX] = 0.6;
  params.fogo_espalhar[FOG_ESTAVEL_IDX] = 1.0;
  params.fogo_espalhar[FOG_BRAZA_IDX] = 0.2;
  params.fogo_espalhar[AGUA_IDX] = 0.0;

  params.vegetacao_pegar_fogo[VEG_CAMPESTRE_IDX] = 0.6;
  params.vegetacao_pegar_fogo[VEG_SAVANICA_IDX] = 1.0;
  params.vegetacao_pegar_fogo[VEG_FLORESTA_IDX] = 0.8;
  params.vegetacao_pegar_fogo[RAIZ_IDX] = 0.5;
  params.vegetacao_pegar_fogo[TERRA_IDX] = 0.0;
  params.vegetacao_pegar_fogo[SUBTERRANEO_IDX] = 0.0;
  params.vegetacao_pegar_fogo[FOG_INICIAL_IDX] = 0.0;
  params.vegetacao_pegar_fogo[FOG_ESTAVEL_IDX] = 0.0;
  params.vegetacao_pegar_fogo[FOG_BRAZA_IDX] = 0.0;
  params.vegetacao_pegar_fogo[AGUA_IDX] = 0.0;

  params.transicoes[AGUA_IDX] = AGUA;
  params.transicoes[VEG_CAMPESTRE_IDX] = FOG_INICIAL;
  params.transicoes[VEG_SAVANICA_IDX] = FOG_INICIAL;
  params.transicoes[VEG_FLORESTA_IDX] = FOG_INICIAL;
  params.transicoes[RAIZ_IDX] = FOG_INICIAL;
  params.transicoes[TERRA_IDX] = VEG_CAMPESTRE;
  params.transicoes[SUBTERRANEO_IDX] = FOG_BRAZA;
  params.transicoes[FOG_INICIAL_IDX] = FOG_ESTAVEL;
  params.transicoes[FOG_ESTAVEL_IDX] = FOG_BRAZA;
  params.transicoes[FOG_BRAZA_IDX] = TERRA;

  MatrizVento vento;
  inicializa_matriz_vento(&vento, 3, 0.5, 0.5, 0.5, N);

  unsigned short focos_iniciais_incendio[2][2] = {{0, 0}, {1, 1}};

  Estado estado_inicial_superficie[ALTURA][LARGURA];
  for (size_t i = 0; i < ALTURA; i++)
  {
    for (size_t j = 0; j < LARGURA; j++)
    {
      estado_inicial_superficie[i][j] = VEG_CAMPESTRE;
    }
  }

  Experimento exp = {
      .output_file_name = "output.json",
      .tresholds_umidade = {
          .treshold1 = 0.25,
          .treshold2 = 0.50,
          .treshold3 = 0.75,
          .treshold4 = 1.0},
      .reticulado = {.umidade = 0.5, .vento = vento, .tempo = 0, .tamanho_vizinhanca = 3}};

  inicializa_reticulado(&exp.reticulado, vento, 3, focos_iniciais_incendio, 2, estado_inicial_superficie);

  run_experimento(&exp, params);
  return 0;
}
