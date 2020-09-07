typedef struct no *Lista;
Lista cria_lista();
int lista_vazia(Lista);
int insere_ord(Lista *, int);
int remove_ord(Lista *, int);
int obtem_posicao(Lista, int indice, int *);
int limpa_lista(Lista *);
int get_size(Lista *);