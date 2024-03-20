#include "reticulado.h"
#include "celula.h"

void inicializa_reticulado(
    Reticulado *r,
    MatrizVento v,
    unsigned short tamanho_matriz_vento,
    unsigned short **focos_iniciais_incendio,
    unsigned short quantidade_focos_iniciais_incendio,
    Estado **estado_inicial_superficie)
{
  r->tempo = 0;

  for (unsigned short i = 0; i < ALTURA; i++)
  {
    for (unsigned short j = 0; j < LARGURA; j++)
    {
      for (unsigned short nivel = 0; nivel < NIVEIS; nivel++)
      {
        if (nivel == ENTERRADO_IDX)
        {
          inicializa_celula(&r->celulas[i][j][nivel], RAIZ);
          continue;
        }

        for (unsigned short foco_idx = 0; foco_idx < quantidade_focos_iniciais_incendio; foco_idx++)
        {
          unsigned short x = focos_iniciais_incendio[foco_idx][0];
          unsigned short y = focos_iniciais_incendio[foco_idx][1];
          if (i == x && j == y)
          {
            inicializa_celula(&r->celulas[i][j][nivel], FOG_INICIAL);
          }
        }
        inicializa_celula(&r->celulas[i][j][nivel], estado_inicial_superficie[i][j]);
      }
    }
  }
}

void inicializa_matriz_vento(MatrizVento *v, unsigned short tamanho_matriz_vento, double coef, double mult_base, double decai, DirecaoVento direcao);
