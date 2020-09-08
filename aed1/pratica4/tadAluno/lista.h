typedef struct no *Lista;
Lista cria_lista();
int lista_vazia(Lista lst);
int insere_elem(Lista *lst, unsigned int matricula, char *nome, float media, int faltas);
int remove_elem(Lista *lst, unsigned int matricula);
int obtem_posicao(Lista lst, int indice, unsigned int *matricula, char *nome, float *media, int *faltas);
int limpa_lista(Lista *lst);
int obtem_tamanho(Lista *lst);