typedef struct lista *Lista;
Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int insere_elem(Lista lst, char *str, int vol, float preco);
int remove_elem(Lista lst, char *str);
int limpa_lista(Lista lst);
int get_posicao(Lista lst, int num, char *str, int *vol, float *preco);
int get_size(Lista lst);