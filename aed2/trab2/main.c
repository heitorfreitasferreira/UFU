#include <stdio.h>
#include "trie.h"

/*
    Integrantes:
    Heitor Freitas Ferreira 11921BCC026
    Kaio Augusto de Souza 11921BCC040
    Luis Gustavo Seiji Tateishi 11921BCC034
*/

int main()
{
    FILE *file = fopen("palavras.txt", "r");
    if (file == NULL)
    {
        printf("palavras.txt não foi encontrado.");
        return 0;
    }

    Trie *trie = createTrie();

    char word[50];
    while (fscanf(file, "%s", word) != EOF)
    {
        if (!insertTrie(trie, word))
        {
            printf("Erro ao inserir a palavra %s\n", word);
        }
    }

    fclose(file);

    int opt = -1;
    while (opt != 0)
    {
        printf("\n=====================================\n");
        printf(" [0] Sair\n");
        printf(" [1] Imprimir trie\n");
        printf(" [2] Autocompletar palavra\n");
        printf(" [3] Remover uma palavra\n");
        printf("=====================================\n");
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
            printf("Insira o prefixo desejado: ");
            scanf("%s", word);
            autocompleteTrie(trie, word);
            break;
        case 3:
            printf("Insira a palavra a ser removida: ");
            scanf("%s", word);
            removeTrie(trie, word);
            break;
        default:
            printf("Opção invalida.");
        }
    }

    return 0;
}
