#define MAX_SIZE 20
typedef struct lista *Lista;
typedef struct
{
  int type;
  float f_info;
  char c_info;
} Dados;
Lista cria_lista();
int lista_vazia(Lista);
int lista_cheia(Lista);
int insere_elem(Lista, Dados);
int remove_elem(Lista, Dados);
int get_posicao(Lista, int, Dados *);
int get_size(Lista);