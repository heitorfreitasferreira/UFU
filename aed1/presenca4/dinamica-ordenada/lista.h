typedef struct lista *Lista;
Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int insere_elem(Lista lst, float num);
int remove_elem(Lista lst, float num);
int limpa_lista(Lista *lst);
float get_posicao(Lista lst, int num);
int get_size(Lista lst);