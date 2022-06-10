
#define R 3
#define C 3
#define TAMANHO_RETICULADO 512
#define qnt_estados 8
#define HORIZONTAL 1024
#define VERTICAL  1024
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

float random_range();
float random_range(int i, int f);
float random_range(int f);

void set_vento(string i, string f, float* matrixCoef);
