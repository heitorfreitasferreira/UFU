#include "celula.h"

void inicializa_celula(Celula *c, Estado inicial)
{
  c->estado = inicial;
  c->tempo_no_estado = 0;
}

unsigned short get_estado_index(Celula *c)
{
  return get_estado_numeric(c->estado);
}

unsigned short get_estado_numeric(Estado e)
{
  return e - '0';
}

bool celula_esta_em_chamas(Celula *c)
{
  return c->estado >= FOG_INICIAL && c->estado <= FOG_BRAZA;
}

bool celula_eh_vegetacao(Celula *c)
{
  return c->estado >= PRIMEIRO_ESTADO_VEGETACAO && c->estado <= ULTIMO_ESTADO_VEGETACAO;
}

bool eh_estado_de_fogo(Estado e)
{
  return e >= PRIMEIRO_ESTADO_FOGO && e <= ULTIMO_ESTADO_FOGO;
}

// Retorna true se a célula mudou de estado (ou seja, se o estado atual é diferente do novo estado)
bool avanca_tempo(Celula *c, Estado novo_estado)
{
  if (c->estado != novo_estado)
  {
    c->estado = novo_estado;
    c->tempo_no_estado = 0;
    return true;
  }
  return false;
}
