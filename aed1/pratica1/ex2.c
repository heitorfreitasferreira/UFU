#include <stdio.h>
#include <stdlib.h>
//CRIAR TIPO BOOL EM C
typedef short int bool;
#define true 1
#define false 0
//
#define tam 20

typedef struct
{
    char nome[30];
    unsigned short int ddd;
    unsigned long long int numero;
    bool fixo;
} ListaTelefonica;
// void printArrayStruct(ListaTelefonica lista, size_t sizeStruct) {

// }
int findInStruct(ListaTelefonica *a, char *nome, int tamanho)
{
    bool achei = false;
    for (size_t i = 0; i < tamanho; i++)
    {
        if (!strcmp(a[i].nome, nome))
        {
            return i;
        }
    }
    return -1;
} //se achar retorna o indice, se não retorna -1
int main()
{
    ListaTelefonica lista[tam];
    int i = 0;
    while (i < tam)
    {
        char tmp[30];
        if (i != 0)
            setbuf(stdin, NULL);
        printf("Nome: ");
        scanf("%[^\n]s", tmp);
        if (!strcmp(tmp, "ACABOU"))
            break;
        strcpy(lista[i].nome, tmp);
        printf("DDD: ");
        scanf("%d", &lista[i].ddd);
        printf("Numero: ");
        scanf("%lld", &lista[i].numero);
        printf("Fixo?(s=1/n=0): ");
        scanf("%d", &lista[i].fixo);

        i++;
    }
    int sizeStruct = i;
    // for (i = 0; i < sizeStruct; i++)
    // {
    //     if (lista[i].fixo==1) printf("Nome: %s\tTelefone fixo: (%d)%d\n", lista[i].nome, lista[i].ddd, lista[i].numero);
    //     else
    //         printf("Nome: %s\tCelular: (%d)%d\n", lista[i].nome, lista[i].ddd, lista[i].numero);
    // }
    while (1)
    {
        char nome[30];
        if (i != 0)
            setbuf(stdin, NULL);
        printf("Nome: ");
        scanf("%[^\n]s", nome);
        if (!strcmp(nome, "FIM"))
            break;
        if (findInStruct(lista, nome, sizeStruct) == -1)
        {
            printf("Nao encontrei isso no seu banco de dados\n");
        }
        else
        {
            int index = findInStruct(lista, nome, sizeStruct);
            (lista[i].fixo == 1) ? printf("Nome: %s\tTelefone fixo: (%d)%d\n", lista[index].nome, lista[index].ddd, lista[index].numero) : printf("Nome: %s\tCelular: (%d)%d\n", lista[index].nome, lista[index].ddd, lista[index].numero);
        }
    }

    return 0;
}
// main
