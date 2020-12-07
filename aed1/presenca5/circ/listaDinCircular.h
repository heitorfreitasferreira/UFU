//Arquivo ListaDinEncadCirc.h

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Lista;

Lista* cria_lista();
struct aluno preenche_dados();
void libera_lista(Lista* li);
int consulta_lista_mat(Lista* li, int mat, struct aluno *al);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);
int remove_lista_matricula(Lista* li, int mat);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia(Lista* li);
void imprime_lista(Lista* li);
void imprime_lista_aprovados(Lista* li);
int sorteia_aluno(Lista* li, int n, struct aluno *al);