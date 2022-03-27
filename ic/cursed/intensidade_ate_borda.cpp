#include <time.h>
#include <iostream>
#include <random>
#include <stdlib.h>
#define solo_exposto 0
#define inicio_fogo 1
#define arvore_queimando 2
#define queima_lenta 3
#define arvore_viva 4
#define TAMANHO_RETICULADO 1024
#define NUMERO_ITERACOES 300
#define NUMERO_EXPERIMENTOS 100
#define DECAIMENTO_QUEIMA_LENTA 0.2
#define DECAIMENTO_INICIO_FOGO 0.6
#define ITERACOES_ATE_PARAR 300

#define R 3
#define C 3
using namespace std;
// Variáveis globais
#pragma region varEStructs
double coef = 1;
unsigned long long int unidades_queimadas = 0;

double matrixCoef[3][3] =
    {
        {coef * 0.12, coef * 0.16, coef * 0.12},
        {coef * 0.08, 0, coef * 0.08},
        {coef * 0.04, coef * 0.002, coef * 0.04}};
typedef struct
{
    int estado, tempo_queimando, tempo_desde_queima;

} Celula;
typedef struct
{
    int iteracoes_ate_apagar;
    int quantidade_quadrante_a, quantidade_quadrante_b, quantidade_quadrante_c, quantidade_quadrante_d;
} DadosAnalise;
typedef struct
{
    float media, desvio_padrao;
} DadosEstatisticos;
Celula reticulado[TAMANHO_RETICULADO + 1][TAMANHO_RETICULADO + 1], aux_reticulado[TAMANHO_RETICULADO][TAMANHO_RETICULADO];
DadosAnalise dadosDilao1993[NUMERO_EXPERIMENTOS], dadosHeitorzera1[NUMERO_EXPERIMENTOS];
#pragma endregion varEStructs
#pragma region funçõesAuxiliares
void rotatematrix(double mat[R][C], int m = 3, int n = 3)
{
    int row = 0, col = 0;
    double prev, curr;

    /*
    row - Starting row index
    m - ending row index
    col - starting column index
    n - ending column index
    i - iterator
    */
    while (row < m && col < n)
    {

        if (row + 1 == m || col + 1 == n)
            break;

        // Store the first element of next row, this
        // element will replace first element of current
        // row
        prev = mat[row + 1][col];

        /* Move elements of first row from the remaining rows */
        for (int i = col; i < n; i++)
        {
            curr = mat[row][i];
            mat[row][i] = prev;
            prev = curr;
        }
        row++;

        /* Move elements of last column from the remaining columns */
        for (int i = row; i < m; i++)
        {
            curr = mat[i][n - 1];
            mat[i][n - 1] = prev;
            prev = curr;
        }
        n--;

        /* Move elements of last row from the remaining rows */
        if (row < m)
        {
            for (int i = n - 1; i >= col; i--)
            {
                curr = mat[m - 1][i];
                mat[m - 1][i] = prev;
                prev = curr;
            }
        }
        m--;

        /* Move elements of first column from the remaining rows */
        if (col < n)
        {
            for (int i = m - 1; i >= row; i--)
            {
                curr = mat[i][col];
                mat[i][col] = prev;
                prev = curr;
            }
        }
        col++;
    }

    // Print rotated matrix
}
void set_vento(string i, string f)
{
    if (i == "n" && f == "s")
    {
    }
    else if (i == "ne" && f == "so")
    {
        rotatematrix(matrixCoef);
    }
    else if (i == "l" && f == "o")
    {
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
    }
    else if (i == "se" && f == "no")
    {

        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
    }
    else if (i == "s" && f == "n")
    {
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
    }
    else if (i == "so" && f == "ne")
    {
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
    }
    else if (i == "o" && f == "l")
    {
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
    }
    else if (i == "no" && f == "se")
    {
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
        rotatematrix(matrixCoef);
    }
}
void print_vizinhanca(double mat[3][3], int m = 3, int n = 3)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}
char mapeiaIcone[5];
void print_reticulado()
{
    mapeiaIcone[solo_exposto] = '.';
    mapeiaIcone[inicio_fogo] = '*';
    mapeiaIcone[arvore_queimando] = '#';
    mapeiaIcone[queima_lenta] = 'o';
    mapeiaIcone[arvore_viva] = '|';
    for (int i = 0; i < TAMANHO_RETICULADO; i++)
    {
        for (int j = 0; j < TAMANHO_RETICULADO; j++)
            printf("%c ", mapeiaIcone[reticulado[i][j].estado]);
        cout << endl;
    }
}
double cleber() { return ((double)rand() / (RAND_MAX)); }
void print_dados(DadosAnalise dados[NUMERO_EXPERIMENTOS])
{
    for (int i = 0; i < NUMERO_EXPERIMENTOS; i++)
    {
        cout << "Execussao nro: " << i << endl;
        cout << "\tIteracoes ate apagar: " << dados[i].iteracoes_ate_apagar << endl;
        cout << "\tQuantidade queimado: " << endl;
        cout << "\t\tQuadrante A: " << dados[i].quantidade_quadrante_a << endl;
        cout << "\t\tQuadrante B: " << dados[i].quantidade_quadrante_b << endl;
        cout << "\t\tQuadrante C: " << dados[i].quantidade_quadrante_c << endl;
        cout << "\t\tQuadrante D: " << dados[i].quantidade_quadrante_d << endl;
    }
}
bool tem_fogo_reticulado(Celula reticulado[TAMANHO_RETICULADO][TAMANHO_RETICULADO])
{
    for (size_t i = 0; i < TAMANHO_RETICULADO; i++)
    {
        for (size_t j = 0; j < TAMANHO_RETICULADO; j++)
        {
            if (reticulado[i][j].estado == inicio_fogo || reticulado[i][j].estado == arvore_queimando || reticulado[i][j].estado == queima_lenta)
            {
                return true;
            }
        }
    }
    return false;
}
bool fogo_chegou_na_borda(Celula reticulado[TAMANHO_RETICULADO][TAMANHO_RETICULADO])
{
    for (size_t i = 0; i < TAMANHO_RETICULADO; i++)
    {
        if (reticulado[i][0].estado == inicio_fogo || reticulado[i][0].estado == arvore_queimando || reticulado[i][0].estado == queima_lenta)
            return true;
    } // Borda vertical esquerda
    for (size_t i = 0; i < TAMANHO_RETICULADO; i++)
    {
        if (reticulado[i][TAMANHO_RETICULADO - 1].estado == inicio_fogo || reticulado[i][TAMANHO_RETICULADO - 1].estado == arvore_queimando || reticulado[i][TAMANHO_RETICULADO - 1].estado == queima_lenta)
            return true;
    } // Borda vertical direita
    for (size_t i = 0; i < TAMANHO_RETICULADO; i++)
    {
        if (reticulado[0][i].estado == inicio_fogo || reticulado[0][i].estado == arvore_queimando || reticulado[0][i].estado == queima_lenta)
            return true;
    } // Borda horizontal superior
    for (size_t i = 0; i < TAMANHO_RETICULADO; i++)
    {
        if (reticulado[TAMANHO_RETICULADO - 1][i].estado == inicio_fogo || reticulado[TAMANHO_RETICULADO - 1][i].estado == arvore_queimando || reticulado[TAMANHO_RETICULADO - 1][i].estado == queima_lenta)
            return true;
    } // Borda horizontal inferior
    return false;
}
#pragma endregion funçõesAuxiliares
#pragma region funçõesAtualizacaoEstado
Celula heitorzera1(Celula n, Celula s, Celula o, Celula l, Celula ne, Celula no, Celula se, Celula so, Celula centro)
{
#pragma region dadosPosicionais
    bool posQueimando[3][3] =
        {
            {no.estado == arvore_queimando, n.estado == arvore_queimando, ne.estado == arvore_queimando},
            {o.estado == arvore_queimando, centro.estado == arvore_queimando, l.estado == arvore_queimando},
            {so.estado == arvore_queimando, s.estado == arvore_queimando, se.estado == arvore_queimando}};
    int somaQueimando = posQueimando[0][0] + posQueimando[0][1] + posQueimando[0][2] + posQueimando[1][0] + posQueimando[1][1] + posQueimando[1][2] + posQueimando[2][0] + posQueimando[2][1] + posQueimando[2][2];
    bool posInicioFogo[3][3] =
        {
            {no.estado == inicio_fogo, n.estado == inicio_fogo, ne.estado == inicio_fogo},
            {o.estado == inicio_fogo, centro.estado == inicio_fogo, l.estado == inicio_fogo},
            {so.estado == inicio_fogo, s.estado == inicio_fogo, se.estado == inicio_fogo}};
    int somaInicioFogo = posInicioFogo[0][0] + posInicioFogo[0][1] + posInicioFogo[0][2] + posInicioFogo[1][0] + posInicioFogo[1][1] + posInicioFogo[1][2] + posInicioFogo[2][0] + posInicioFogo[2][1] + posInicioFogo[2][2];
    bool posQueimaLenta[3][3] =
        {
            {no.estado == arvore_queimando, n.estado == arvore_queimando, ne.estado == arvore_queimando},
            {o.estado == arvore_queimando, centro.estado == arvore_queimando, l.estado == arvore_queimando},
            {so.estado == arvore_queimando, s.estado == arvore_queimando, se.estado == arvore_queimando}};
    int somaQueimaLenta = posQueimaLenta[0][0] + posQueimaLenta[0][1] + posQueimaLenta[0][2] + posQueimaLenta[1][0] + posQueimaLenta[1][1] + posQueimaLenta[1][2] + posQueimaLenta[2][0] + posQueimaLenta[2][1] + posQueimaLenta[2][2];

    bool posTemFogo[3][3] =
        {
            {posInicioFogo[0][0] || posQueimando[0][0] || posQueimaLenta[0][0], posInicioFogo[0][1] || posQueimando[0][1] || posQueimaLenta[0][1], posInicioFogo[0][2] || posQueimando[0][2] || posQueimaLenta[0][2]},
            {posInicioFogo[1][0] || posQueimando[1][0] || posQueimaLenta[1][0], posInicioFogo[1][1] || posQueimando[1][1] || posQueimaLenta[1][1], posInicioFogo[1][2] || posQueimando[1][2] || posQueimaLenta[1][2]},
            {posInicioFogo[2][0] || posQueimando[2][0] || posQueimaLenta[2][0], posInicioFogo[2][1] || posQueimando[2][1] || posQueimaLenta[2][1], posInicioFogo[2][2] || posQueimando[2][2] || posQueimaLenta[2][2]}};

    int somaFogo = somaInicioFogo + somaQueimaLenta + somaQueimando;
#pragma endregion dadosPosicionais
#pragma region avançandoInfoCelula
    if (centro.estado == solo_exposto)
        centro.tempo_desde_queima++;
    if (centro.estado >= inicio_fogo && centro.estado <= queima_lenta)
        centro.tempo_queimando++;
#pragma endregion avançandoInfoCelula
#pragma region atualizandoEstado
    if (centro.tempo_queimando > 2)
        centro.estado = arvore_queimando;
    if (centro.tempo_queimando > 6)
        centro.estado = queima_lenta;
    if (centro.tempo_queimando > 16)
    {
        centro.estado = solo_exposto;
        centro.tempo_queimando = 0;
    }
#pragma region renascimento
    if (centro.estado == solo_exposto && cleber() <= (centro.tempo_desde_queima * centro.tempo_desde_queima / 20000000))
        centro.estado = arvore_viva;
#pragma endregion renascimento
    if (centro.estado == arvore_viva && somaFogo > 0)
    {
        for (size_t i = 0; i < 3; i++)
        {
            double cleberMatriz[3][3] = {
                {cleber(), cleber(), cleber()},
                {cleber(), 0, cleber()},
                {cleber(), cleber(), cleber()}};
            for (size_t j = 0; j < 3; j++)
            {
                if (posInicioFogo[i][j] && cleberMatriz[i][j] < matrixCoef[i][j] * DECAIMENTO_INICIO_FOGO)
                {
                    // unidades_queimadas++;
                    centro.estado = inicio_fogo;
                }
                if (posQueimando[i][j] && cleberMatriz[i][j] < matrixCoef[i][j])
                {
                    // unidades_queimadas++;
                    centro.estado = inicio_fogo;
                }
                if (posQueimaLenta[i][j] && cleberMatriz[i][j] < matrixCoef[i][j] * DECAIMENTO_QUEIMA_LENTA)
                {
                    // unidades_queimadas++;
                    centro.estado = inicio_fogo;
                }
            }
        }
    }
#pragma endregion funçõesAtualizacaoEstado
    return centro;
}
int deterministico(int n, int s, int o, int l, int ne, int no, int se, int so, int centro)
{
    double p = cleber();
    double f = cleber();
    int total = (n == arvore_queimando) + (s == arvore_queimando) + (o == arvore_queimando) + (l == arvore_queimando) + (ne == arvore_queimando) + (no == arvore_queimando) + (se == arvore_queimando) + (so == arvore_queimando);
    if (centro == arvore_queimando)
        return solo_exposto;
    if (centro == arvore_viva && total > 0)
        return arvore_queimando;
    if (centro == solo_exposto && p <= 0.01)
        return arvore_viva;
    if (centro == arvore_viva && f <= 0.0005)
        return arvore_queimando; // 0.0005
    return centro;
}

Celula dilao1993(Celula n, Celula s, Celula o, Celula l, Celula ne, Celula no, Celula se, Celula so, Celula centro)
{
    // double p = cleber();
    //  double f = cleber();
    //  int total = (n.estado==arvore_queimando)+(s.estado==arvore_queimando)+(o.estado==arvore_queimando)+(l.estado==arvore_queimando)+(ne.estado==arvore_queimando)+(no.estado==arvore_queimando)+(se.estado==arvore_queimando)+(so.estado==arvore_queimando);
    bool posQueimando[3][3] =
        {
            {no.estado == arvore_queimando, n.estado == arvore_queimando, ne.estado == arvore_queimando},
            {o.estado == arvore_queimando, centro.estado == arvore_queimando, l.estado == arvore_queimando},
            {so.estado == arvore_queimando, s.estado == arvore_queimando, se.estado == arvore_queimando}};
    int somaQueimando = posQueimando[0][0] + posQueimando[0][1] + posQueimando[0][2] + posQueimando[1][0] + posQueimando[1][1] + posQueimando[1][2] + posQueimando[2][0] + posQueimando[2][1] + posQueimando[2][2];
    bool posInicioFogo[3][3] =
        {
            {no.estado == inicio_fogo, n.estado == inicio_fogo, ne.estado == inicio_fogo},
            {o.estado == inicio_fogo, centro.estado == inicio_fogo, l.estado == inicio_fogo},
            {so.estado == inicio_fogo, s.estado == inicio_fogo, se.estado == inicio_fogo}};
    int somaInicioFogo = posInicioFogo[0][0] + posInicioFogo[0][1] + posInicioFogo[0][2] + posInicioFogo[1][0] + posInicioFogo[1][1] + posInicioFogo[1][2] + posInicioFogo[2][0] + posInicioFogo[2][1] + posInicioFogo[2][2];
    bool posQueimaLenta[3][3] =
        {
            {no.estado == arvore_queimando, n.estado == arvore_queimando, ne.estado == arvore_queimando},
            {o.estado == arvore_queimando, centro.estado == arvore_queimando, l.estado == arvore_queimando},
            {so.estado == arvore_queimando, s.estado == arvore_queimando, se.estado == arvore_queimando}};
    int somaQueimaLenta = posQueimaLenta[0][0] + posQueimaLenta[0][1] + posQueimaLenta[0][2] + posQueimaLenta[1][0] + posQueimaLenta[1][1] + posQueimaLenta[1][2] + posQueimaLenta[2][0] + posQueimaLenta[2][1] + posQueimaLenta[2][2];

    bool posTemFogo[3][3] =
        {
            {posInicioFogo[0][0] || posQueimando[0][0] || posQueimaLenta[0][0], posInicioFogo[0][1] || posQueimando[0][1] || posQueimaLenta[0][1], posInicioFogo[0][2] || posQueimando[0][2] || posQueimaLenta[0][2]},
            {posInicioFogo[1][0] || posQueimando[1][0] || posQueimaLenta[1][0], posInicioFogo[1][1] || posQueimando[1][1] || posQueimaLenta[1][1], posInicioFogo[1][2] || posQueimando[1][2] || posQueimaLenta[1][2]},
            {posInicioFogo[2][0] || posQueimando[2][0] || posQueimaLenta[2][0], posInicioFogo[2][1] || posQueimando[2][1] || posQueimaLenta[2][1], posInicioFogo[2][2] || posQueimando[2][2] || posQueimaLenta[2][2]}};

    int somaFogo = somaInicioFogo + somaQueimaLenta + somaQueimando;

    if (centro.estado >= inicio_fogo && centro.estado <= queima_lenta)
    {
        centro.tempo_queimando++;
    }
    if (centro.estado == solo_exposto)
    {
        centro.tempo_desde_queima++;
    }
    if (centro.tempo_queimando > 0)
    {
        centro.estado = arvore_queimando;
    }
    if (centro.tempo_queimando > 1)
    {
        centro.estado = queima_lenta;
    }
    if (centro.tempo_queimando > 2)
    {
        centro.estado = solo_exposto;
        centro.tempo_queimando = 0;
    }
    if (centro.estado == arvore_viva && somaFogo > 0)
    {
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                if (posTemFogo[i][j] && cleber() < matrixCoef[i][j])
                {
                    // unidades_queimadas++;
                    centro.estado = inicio_fogo;
                }
            }
        }
    }
    return centro;
}
#pragma endregion
#pragma region funçõesAnalize
int quantidade_fogo_reticulado(Celula reticulado[TAMANHO_RETICULADO][TAMANHO_RETICULADO])
{
    int soma = 0;
    for (size_t i = 0; i < TAMANHO_RETICULADO; i++)
    {
        for (size_t j = 0; j < TAMANHO_RETICULADO; j++)
        {
            if (reticulado[i][j].estado == inicio_fogo || reticulado[i][j].estado == arvore_queimando || reticulado[i][j].estado == queima_lenta)
            {
                soma++;
            }
        }
    }
    return soma;
}
DadosEstatisticos analise_estatistica_dados(DadosAnalise dados[NUMERO_EXPERIMENTOS])
{
    DadosEstatisticos estatisticos;
    for (int i = 0; i < NUMERO_EXPERIMENTOS; i++)
    {
        estatisticos.media += dados[i].iteracoes_ate_apagar;
    }
    estatisticos.media /= NUMERO_EXPERIMENTOS;
    for (int i = 0; i < NUMERO_EXPERIMENTOS; i++)
    {
        estatisticos.desvio_padrao += pow(dados[i].iteracoes_ate_apagar - estatisticos.media, 2);
    }
    estatisticos.desvio_padrao /= NUMERO_EXPERIMENTOS;
    return estatisticos;
}
bool escreve_dados_analise(DadosAnalise dados[NUMERO_EXPERIMENTOS], char *nome_arquivo)
{
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL)
        return false;

    fprintf(arquivo, "iteracoes_ate_apagar,quantidade_quadrante_a,quantidade_quadrante_b,quantidade_quadrante_c,quantidade_quadrante_d\n");

    for (int i = 0; i < NUMERO_EXPERIMENTOS; i++)
    {
        fprintf(arquivo, "%d,%d,%d,%d,%d\n", dados[i].iteracoes_ate_apagar, dados[i].quantidade_quadrante_a, dados[i].quantidade_quadrante_b, dados[i].quantidade_quadrante_c, dados[i].quantidade_quadrante_d);
    }

    fclose(arquivo);
    return true;
}

bool escreve_dados_analise_individual(DadosAnalise dados, char *nome_arquivo)
{
    FILE *arquivo = fopen(nome_arquivo, "a");
    if (arquivo == NULL)
        return false;

    // fprintf(arquivo, "iteracoes_ate_apagar,quantidade_quadrante_a,quantidade_quadrante_b,quantidade_quadrante_c,quantidade_quadrante_d\n");

    fprintf(arquivo, "%d,%d,%d,%d,%d\n", dados.iteracoes_ate_apagar, dados.quantidade_quadrante_a, dados.quantidade_quadrante_b, dados.quantidade_quadrante_c, dados.quantidade_quadrante_d);

    fclose(arquivo);
    return true;
}
void analise_quadrante(int i, int j, int iteracao, char *modelo)
{
    if (modelo == "heitorzera1")
    {
        if (i < TAMANHO_RETICULADO / 2 && j < TAMANHO_RETICULADO / 2)
        {
            dadosHeitorzera1[iteracao].quantidade_quadrante_b++;
        }
        if (i < TAMANHO_RETICULADO / 2 && j >= TAMANHO_RETICULADO / 2)
        {
            dadosHeitorzera1[iteracao].quantidade_quadrante_a++;
        }
        if (i >= TAMANHO_RETICULADO / 2 && j < TAMANHO_RETICULADO / 2)
        {
            dadosHeitorzera1[iteracao].quantidade_quadrante_c++;
        }
        if (i >= TAMANHO_RETICULADO / 2 && j >= TAMANHO_RETICULADO / 2)
        {
            dadosHeitorzera1[iteracao].quantidade_quadrante_d++;
        }
    }
    if (modelo == "dilao1993")
    {
        if (i < TAMANHO_RETICULADO / 2 && j < TAMANHO_RETICULADO / 2)
        {
            dadosDilao1993[iteracao].quantidade_quadrante_b++;
        }
        if (i < TAMANHO_RETICULADO / 2 && j >= TAMANHO_RETICULADO / 2)
        {
            dadosDilao1993[iteracao].quantidade_quadrante_a++;
        }
        if (i >= TAMANHO_RETICULADO / 2 && j < TAMANHO_RETICULADO / 2)
        {
            dadosDilao1993[iteracao].quantidade_quadrante_c++;
        }
        if (i >= TAMANHO_RETICULADO / 2 && j >= TAMANHO_RETICULADO / 2)
        {
            dadosDilao1993[iteracao].quantidade_quadrante_d++;
        }
    }
}
#pragma endregion funçõesAnalize

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    cleber();

#pragma region zerandoAnaliseDados
    for (int i = 0; i < NUMERO_EXPERIMENTOS; i++)
    {
        dadosHeitorzera1[i].iteracoes_ate_apagar = 0;
        dadosHeitorzera1[i].quantidade_quadrante_a = 0;
        dadosHeitorzera1[i].quantidade_quadrante_b = 0;
        dadosHeitorzera1[i].quantidade_quadrante_c = 0;
        dadosHeitorzera1[i].quantidade_quadrante_d = 0;
        /*-------------------------------------------*/
        dadosDilao1993[i].iteracoes_ate_apagar = 0;
        dadosDilao1993[i].quantidade_quadrante_a = 0;
        dadosDilao1993[i].quantidade_quadrante_b = 0;
        dadosDilao1993[i].quantidade_quadrante_c = 0;
        dadosDilao1993[i].quantidade_quadrante_d = 0;
    }
#pragma endregion zeroandoAnaliseDados
#pragma region visualizaçãoInicial
    /*
    print_reticulado();
    getchar();
    */
    ;
#pragma endregion visualizaçãoInicial

#pragma region Heitorzera1_coef1
    coef = 1;
    for (size_t k = 0; k < NUMERO_EXPERIMENTOS; k++)
    {
        srand(k);
#pragma region zerarReticulado

        for (size_t i = 0; i < TAMANHO_RETICULADO; i++)
        {
            for (size_t j = 0; j < TAMANHO_RETICULADO; j++)
            {
                reticulado[i][j].estado = arvore_viva;
                reticulado[i][j].tempo_desde_queima = 0;
                reticulado[i][j].tempo_queimando = 0;
            }
        }
        reticulado[TAMANHO_RETICULADO / 2][TAMANHO_RETICULADO / 2].estado = arvore_queimando;
        for (size_t i = 0; i < TAMANHO_RETICULADO; i++)
        {
            reticulado[i][TAMANHO_RETICULADO].estado = solo_exposto;
            reticulado[i][TAMANHO_RETICULADO].tempo_desde_queima = 0;
            reticulado[i][TAMANHO_RETICULADO].tempo_desde_queima = 0;
            /* -------------------------------------------------- */
            reticulado[TAMANHO_RETICULADO][i].estado = solo_exposto;
            reticulado[TAMANHO_RETICULADO][i].tempo_queimando = 0;
            reticulado[TAMANHO_RETICULADO][i].tempo_queimando = 0;
        }
#pragma endregion zerarReticulado
#pragma region avançaReticuladoAtéQueimar
        int iteracao = 0;
        do
        {
            // Calcula novos estados
            for (size_t i = 0; i < TAMANHO_RETICULADO; i++)
            {
                for (size_t j = 0; j < TAMANHO_RETICULADO; j++)
                {
                    int cima, baixo, esquerda, direita;
                    if (i == 0)
                        cima = TAMANHO_RETICULADO;
                    else
                        cima = i - 1;
                    baixo = i + 1;
                    if (j == 0)
                        esquerda = TAMANHO_RETICULADO;
                    else
                        esquerda = j - 1;
                    direita = j + 1;
                    aux_reticulado[i][j] = heitorzera1(reticulado[cima][j],         // n
                                                       reticulado[baixo][j],        // s
                                                       reticulado[i][esquerda],     // o
                                                       reticulado[i][direita],      // l
                                                       reticulado[cima][direita],   // ne
                                                       reticulado[cima][esquerda],  // no
                                                       reticulado[baixo][direita],  // se
                                                       reticulado[baixo][esquerda], // so
                                                       reticulado[i][j]             // centro
                    );
                    if (aux_reticulado[i][j].estado == inicio_fogo && reticulado[i][j].estado != inicio_fogo)
                        analise_quadrante(i, j, k, "heitorzera1");
                }
            }
            // Adiciona os estados na matriz principal
            for (size_t i = 0; i < TAMANHO_RETICULADO; i++)
            {
                for (size_t j = 0; j < TAMANHO_RETICULADO; j++)
                {
                    reticulado[i][j] = aux_reticulado[i][j];
                }
            }
#pragma region Visualizacao

            // print_reticulado();

#pragma endregion Visualizacao
            iteracao++;
        } while (!fogo_chegou_na_borda(aux_reticulado) && tem_fogo_reticulado(aux_reticulado));
#pragma endregion avançaReticuladoAtéQueimar
// cout<<"Experimento "<<k<<" terminou em "<<iteracao<<" iteracoes"<<endl;
#pragma region salvaDados
        dadosHeitorzera1[k].iteracoes_ate_apagar = iteracao;
        escreve_dados_analise_individual(dadosHeitorzera1[k], "heitorzera1_coef1_ate_borda.csv");
#pragma endregion salvaDados
    }
#pragma region salvaDadosArquivo
    // escreve_dados_analise(dadosHeitorzera1, "heitorzera1_coef1_ate_borda.csv");
    /*cout << "Heitorzeira1" << endl;
    print_dados(dadosHeitorzera1);
    cout << "Media: " << pedro_franklin.media << endl;
    cout << "Desvio Padrao: " << pedro_franklin.desvio_padrao << endl;
    */
    DadosEstatisticos pedro_franklin = analise_estatistica_dados(dadosHeitorzera1);
#pragma endregion salvaDadosArquivo
#pragma endregion Heitorzera1_coef1
#pragma region Heitorzera1_coef_meio
    coef = 0.5;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            matrixCoef[i][j] *= 0.5;
        }
    }

    for (size_t k = 0; k < NUMERO_EXPERIMENTOS; k++)
    {
        srand(k);
#pragma region zerarReticulado

        for (size_t i = 0; i < TAMANHO_RETICULADO; i++)
        {
            for (size_t j = 0; j < TAMANHO_RETICULADO; j++)
            {
                reticulado[i][j].estado = arvore_viva;
                reticulado[i][j].tempo_desde_queima = 0;
                reticulado[i][j].tempo_queimando = 0;
            }
        }
        reticulado[TAMANHO_RETICULADO / 2][TAMANHO_RETICULADO / 2].estado = arvore_queimando;
        for (size_t i = 0; i < TAMANHO_RETICULADO; i++)
        {
            reticulado[i][TAMANHO_RETICULADO].estado = solo_exposto;
            reticulado[i][TAMANHO_RETICULADO].tempo_desde_queima = 0;
            reticulado[i][TAMANHO_RETICULADO].tempo_desde_queima = 0;
            /* -------------------------------------------------- */
            reticulado[TAMANHO_RETICULADO][i].estado = solo_exposto;
            reticulado[TAMANHO_RETICULADO][i].tempo_queimando = 0;
            reticulado[TAMANHO_RETICULADO][i].tempo_queimando = 0;
        }
#pragma endregion zerarReticulado
#pragma region avançaReticuladoAtéQueimar
        int iteracao = 0;
        do
        {
            // Calcula novos estados
            for (size_t i = 0; i < TAMANHO_RETICULADO; i++)
            {
                for (size_t j = 0; j < TAMANHO_RETICULADO; j++)
                {
                    int cima, baixo, esquerda, direita;
                    if (i == 0)
                        cima = TAMANHO_RETICULADO;
                    else
                        cima = i - 1;
                    baixo = i + 1;
                    if (j == 0)
                        esquerda = TAMANHO_RETICULADO;
                    else
                        esquerda = j - 1;
                    direita = j + 1;
                    aux_reticulado[i][j] = heitorzera1(reticulado[cima][j],         // n
                                                       reticulado[baixo][j],        // s
                                                       reticulado[i][esquerda],     // o
                                                       reticulado[i][direita],      // l
                                                       reticulado[cima][direita],   // ne
                                                       reticulado[cima][esquerda],  // no
                                                       reticulado[baixo][direita],  // se
                                                       reticulado[baixo][esquerda], // so
                                                       reticulado[i][j]             // centro
                    );
                    if (aux_reticulado[i][j].estado == inicio_fogo && reticulado[i][j].estado != inicio_fogo)
                        analise_quadrante(i, j, k, "heitorzera1");
                }
            }
            // Adiciona os estados na matriz principal
            for (size_t i = 0; i < TAMANHO_RETICULADO; i++)
            {
                for (size_t j = 0; j < TAMANHO_RETICULADO; j++)
                {
                    reticulado[i][j] = aux_reticulado[i][j];
                }
            }
#pragma region Visualizacao

            // print_reticulado();
#pragma endregion Visualizacao
            iteracao++;
        } while (!fogo_chegou_na_borda(aux_reticulado) && tem_fogo_reticulado(aux_reticulado));
#pragma endregion avançaReticuladoAtéQueimar
// cout<<"Experimento "<<k<<" terminou em "<<iteracao<<" iteracoes"<<endl;
#pragma region salvaDados
        dadosHeitorzera1[k].iteracoes_ate_apagar = iteracao;
        escreve_dados_analise_individual(dadosHeitorzera1[k], "heitorzera1_coef0.5_ate_borda.csv");
#pragma endregion salvaDados
    }
#pragma region salvaDadosArquivo
    // escreve_dados_analise(dadosHeitorzera1, "heitorzera1_coef0,5_ate_borda.csv");
    cout << "Heitorzeira1" << endl;
    print_dados(dadosHeitorzera1);
    pedro_franklin = analise_estatistica_dados(dadosHeitorzera1);
    cout << "Media: " << pedro_franklin.media << endl;
    cout << "Desvio Padrao: " << pedro_franklin.desvio_padrao << endl;
#pragma endregion salvaDadosArquivo
#pragma endregion Heitorzera1_coef_meio
#pragma region Heitorzera1_coef_umemeio
    coef = 1.5;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            matrixCoef[i][j] *= 3;
        }
    }
    for (size_t k = 0; k < NUMERO_EXPERIMENTOS; k++)
    {
        srand(k);
#pragma region zerarReticulado

        for (size_t i = 0; i < TAMANHO_RETICULADO; i++)
        {
            for (size_t j = 0; j < TAMANHO_RETICULADO; j++)
            {
                reticulado[i][j].estado = arvore_viva;
                reticulado[i][j].tempo_desde_queima = 0;
                reticulado[i][j].tempo_queimando = 0;
            }
        }
        reticulado[TAMANHO_RETICULADO / 2][TAMANHO_RETICULADO / 2].estado = arvore_queimando;
        for (size_t i = 0; i < TAMANHO_RETICULADO; i++)
        {
            reticulado[i][TAMANHO_RETICULADO].estado = solo_exposto;
            reticulado[i][TAMANHO_RETICULADO].tempo_desde_queima = 0;
            reticulado[i][TAMANHO_RETICULADO].tempo_desde_queima = 0;
            /* -------------------------------------------------- */
            reticulado[TAMANHO_RETICULADO][i].estado = solo_exposto;
            reticulado[TAMANHO_RETICULADO][i].tempo_queimando = 0;
            reticulado[TAMANHO_RETICULADO][i].tempo_queimando = 0;
        }
#pragma endregion zerarReticulado
#pragma region avançaReticuladoAtéQueimar
        int iteracao = 0;
        do
        {
            // Calcula novos estados
            for (size_t i = 0; i < TAMANHO_RETICULADO; i++)
            {
                for (size_t j = 0; j < TAMANHO_RETICULADO; j++)
                {
                    int cima, baixo, esquerda, direita;
                    if (i == 0)
                        cima = TAMANHO_RETICULADO;
                    else
                        cima = i - 1;
                    baixo = i + 1;
                    if (j == 0)
                        esquerda = TAMANHO_RETICULADO;
                    else
                        esquerda = j - 1;
                    direita = j + 1;
                    aux_reticulado[i][j] = heitorzera1(reticulado[cima][j],         // n
                                                       reticulado[baixo][j],        // s
                                                       reticulado[i][esquerda],     // o
                                                       reticulado[i][direita],      // l
                                                       reticulado[cima][direita],   // ne
                                                       reticulado[cima][esquerda],  // no
                                                       reticulado[baixo][direita],  // se
                                                       reticulado[baixo][esquerda], // so
                                                       reticulado[i][j]             // centro
                    );
                    if (aux_reticulado[i][j].estado == inicio_fogo && reticulado[i][j].estado != inicio_fogo)
                        analise_quadrante(i, j, k, "heitorzera1");
                }
            }
            // Adiciona os estados na matriz principal
            for (size_t i = 0; i < TAMANHO_RETICULADO; i++)
            {
                for (size_t j = 0; j < TAMANHO_RETICULADO; j++)
                {
                    reticulado[i][j] = aux_reticulado[i][j];
                }
            }
#pragma region Visualizacao

            // print_reticulado();
#pragma endregion Visualizacao
            iteracao++;
        } while (!fogo_chegou_na_borda(aux_reticulado) && tem_fogo_reticulado(aux_reticulado));
#pragma endregion avançaReticuladoAtéQueimar
// cout<<"Experimento "<<k<<" terminou em "<<iteracao<<" iteracoes"<<endl;
#pragma region salvaDados
        dadosHeitorzera1[k].iteracoes_ate_apagar = iteracao;
        escreve_dados_analise_individual(dadosHeitorzera1[k], "heitorzera1_coef1,5_ate_borda.csv");
#pragma endregion salvaDados
    }
#pragma region salvaDadosArquivo
    // escreve_dados_analise(dadosHeitorzera1, "heitorzera1_coef1,5_ate_borda.csv");
    cout << "Heitorzeira1" << endl;
    print_dados(dadosHeitorzera1);
    pedro_franklin = analise_estatistica_dados(dadosHeitorzera1);
    cout << "Media: " << pedro_franklin.media << endl;
    cout << "Desvio Padrao: " << pedro_franklin.desvio_padrao << endl;
#pragma endregion salvaDadosArquivo
#pragma endregion Heitorzera1_coef_umemeio

    return 0;
}
