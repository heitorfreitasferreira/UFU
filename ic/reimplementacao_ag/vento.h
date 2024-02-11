#define N 0
#define NE 1
#define E 2
#define SE 3
#define S 4
#define SO 5
#define O 6
#define NO 7

typedef unsigned short DirecaoVento;
typedef float **MatrizVento;

// Função: criaMatrizVento
// Cria uma matriz de vento com valores aleatórios
// Parâmetros:
// - int n: número de linhas da matriz
// - int m: número de colunas da matriz
// Retorno:
// - MatrizVento: matriz de vento
MatrizVento criaMatrizVento(int size, double coef, double mult_base, double decai, DirecaoVento direcao);
