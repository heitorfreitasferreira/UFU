#include <stdio.h>
#include "trie.h"

/*
    Integrantes:
    Heitor Freitas Ferreira 11921BCC
    Kaio Augusto de Souza 11921BCC040
    Luis Gustavo Seiji Tateishi 11921BCC034
*/

int main()
{
    int opt = -1;
    char word[50];

    Trie *trie = createTrie();
    FILE *file = fopen("palavras.txt", "r");
    if (file == NULL)
    {
        printf("palavras.txt não foi encontrado.");
        return 0;
    }

    while (fscanf(file, "%s", word) != EOF)
    {
        if (!insertTrie(trie, word))
        {
            printf("Erro ao inserir a palavra %s\n", word);
        }
    }

    fclose(file);

    while (opt != 0)
    {
        printf("\n=====================================\n");
        printf(" [0] Sair\n");
        printf(" [1] Imprimir trie\n");
        printf(" [2] Autocompletar palavra\n");
        printf("\n=====================================\n");
        printf("Selecione uma opcao: ");

        scanf("%d", &opt);
        switch (opt)
        {
        case 0:
            printf("Finalizando...\n");
            return 1;
        case 1:
            printTrie(trie);
            break;
        case 2:
            autocompleteTrie(trie, word);
            break;
        default:
            printf("Opção invalida.");
            break;
        }
    }

    return 0;
}
