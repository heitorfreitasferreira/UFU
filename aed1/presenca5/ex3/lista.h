typedef struct lista *Lista;
int lista_vazia(Lista *);
Lista cria_lista();
int insere_final(Lista *, int);
int insere_inicio(Lista *, int);
int remove_inicio(Lista *, int *);
int remove_final(Lista *, int *);
int obtem_valor_elem(Lista *, int, int *);
// int obtem_tamanho(Lista *);