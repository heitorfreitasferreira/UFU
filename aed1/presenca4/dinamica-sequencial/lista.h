typedef struct no *Lista;
Lista cria_lista();
int lista_vazia(Lista lst);
int insere_elem(Lista *lst, char elem);
int remove_elem(Lista *lst, char elem);
int obtem_posicao(Lista lst, int indice, char *carac);
int limpa_lista(Lista *lst);
int obtem_tamanho(Lista *lst);