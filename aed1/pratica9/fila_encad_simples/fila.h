//Tipos da estrutura
typedef struct bebida
{
  char nome[30];
  int vol;
  float preco;
} Bebida;
typedef struct fila *Fila;
//Metodos das estruturas
Fila cria_fila();
int fila_vazia(Fila);
int push(Fila, Bebida);
int shift(Fila, Bebida *);
int esvazia_fila(Fila queue);
int apaga_fila(Fila *queue);
int tamanho_fila(Fila queue);