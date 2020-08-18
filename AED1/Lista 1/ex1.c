#include <stdio.h>
#include <stdlib.h>
//CRIAR TIPO BOOL EM C
typedef short int bool;
#define true 1
#define false 0
//
#define tam 20

typedef struct {
    char nome[30];
    unsigned short int ddd;
    unsigned long long int numero;
    bool fixo;
}ListaTelefonica;
// void printArrayStruct(ListaTelefonica lista, size_t sizeStruct) {

// }
int main() {
    ListaTelefonica lista[tam];
    int i = 0;
    while (i<tam) {
        char tmp[30];
        if (i!=0) setbuf(stdin, NULL);
        printf("Nome: ");
        scanf("%[^\n]s", tmp);
        if (!strcmp(tmp, "ACABOU")) break;
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
    for (i = 0; i < sizeStruct; i++)
    {
        if (lista[i].fixo==1) printf("Nome: %s\tTelefone fixo: (%d)%d\n", lista[i].nome, lista[i].ddd, lista[i].numero);
        else
            printf("Nome: %s\tCelular: (%d)%d\n", lista[i].nome, lista[i].ddd, lista[i].numero);
    }

    return 0;
}
// main
