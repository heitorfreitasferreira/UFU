typedef struct lista *Lista;
int lista_vazia(Lista *);
Lista cria_lista();
int insere_elem(Lista *, int);
int insere_ord(Lista *, int);
int remove_elem(Lista *, int);
int remove_ord(Lista *, int);
int obtem_valor_elem(Lista *lst, int index, int *result);
// int obtem_tamanho(Lista *);