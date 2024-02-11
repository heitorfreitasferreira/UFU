#define AGUA '0'
#define VEG_CAMPESTRE '1'
#define VEG_SAVANICA '2'
#define VEG_FLORESTA '3'
#define RAIZ '4'
#define FOG_INICIAL '5'
#define FOG_ESTAVEL '6'
#define FOG_BRAZA '7'
#define TERRA '8'
#define SUBTERRANEO '9'

#define AGUA_IDX 0
#define VEG_CAMPESTRE_IDX 1
#define VEG_SAVANICA_IDX 2
#define VEG_FLORESTA_IDX 3
#define RAIZ_IDX 4
#define FOG_INICIAL_IDX 5
#define FOG_ESTAVEL_IDX 6
#define FOG_BRAZA_IDX 7
#define TERRA_IDX 8
#define SUBTERRANEO_IDX 9

#define QUANTIDADE_ESTADOS 10

#define PRIMEIRO_ESTADO_VEGETACAO 1
#define ULTIMO_ESTADO_VEGETACAO 3

#define PRIMEIRO_ESTADO_FOGO 5
#define ULTIMO_ESTADO_FOGO 7

typedef char Estado;
typedef char *String;
typedef short TempoNoEstado;
typedef Estado **Vizinhanca;

typedef unsigned short bool;
#define false 0
#define true 1
// [0 = false ou 1 = true ]

typedef struct
{
  Estado estado;                 /**< O estado da célula. */
  TempoNoEstado tempo_no_estado; /**< O tempo que a célula permaneceu no estado atual. */
} Celula;

void inicializa_celula(Celula *c, Estado inicial);

bool celula_esta_em_chamas(Celula *c);

unsigned short int get_estado_index(Celula *c);
unsigned short int get_estado_numeric(Estado e);

// Retorna true se a célula mudou de estado (ou seja, se o estado atual é diferente do novo estado)
bool avanca_tempo(Celula *c, Estado novo_estado);
bool celula_eh_vegetacao(Celula *c);
bool eh_estado_de_fogo(Estado e);