#define string_size 30
#define max 20
typedef struct campo
{
  char string[string_size];
} String;
typedef struct lista *Fila;
Fila cria_fila();
int fila_vazia(Fila);
int fila_cheia(Fila);
int push(Fila, char *);
int shift(Fila, char *);
// int limpa_fila(Fila);
// float get_posicao(Fila, int);
// int get_size(Fila);