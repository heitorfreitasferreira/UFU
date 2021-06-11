#include <stdlib.h>
#include <string.h>
#include "trie.h"

#include <stdio.h>

Trie *createTrie()
{

    Trie *trie = (Trie *)malloc(sizeof(Trie));
    *trie = (Trie)malloc(sizeof(struct node));

    if (*trie != NULL)
    {
        memset((*trie)->child, 0, sizeof(struct node));
        (*trie)->end = 0;

        /*for (int i = 0; i < ALPHABET_SIZE; ++i) {
            (*trie)->child[i] = NULL;
        }*/
    }

    return trie;
}

void freeTrie(Trie *trie)
{
    free(trie);
    trie = NULL;
}

int insertTrie(Trie *trie, char *str)
{
    if (trie == NULL)
        return 0;

    Trie node = *trie;
    for (int i = 0; i < strlen(str); ++i)
    {
        int index = str[i] - 'a';
        if (node->child[index] == NULL)
        {
            node->child[index] = (Trie)malloc(sizeof(struct node));
            //memset(node->child[index], 0, sizeof(struct node));

            node->child[index]->end = 0;
            for (int j = 0; j < ALPHABET_SIZE; ++j)
            {
                node->child[index]->child[j] = NULL;
            }
        }

        node = node->child[index];
    }

    if (node->end)
    {
        return 0;
    }
    else
    {
        node->end = 1;
        return 1;
    }
}

int findTrie(Trie *trie, char *str)
{
    if (trie == NULL)
        return 0;

    Trie node = *trie;
    for (int i = 0; i < strlen(str); ++i)
    {
        int index = str[i] - 'a';
        node = node->child[index];

        if (node == NULL)
            return 0;
    }

    return 1;
}

int removeTrie(Trie *trie, char *str)
{
    if (trie == NULL)
        return 0;

    Trie node = *trie;
    for (int i = 0; i < strlen(str); ++i)
    {
        int index = str[i] - 'a';
        if (node->child[index] == NULL)
        {
            return 0;
        }
        else
        {
            node = node->child[index];
        }
    }

    return 1;
}

void recursivePrint(Trie trie, char *str, int size)
{
    char newStr[size + 2];
    memcpy(newStr, str, size);
    newStr[size + 1] = 0;

    if (trie->end)
    {
        printf("%s\n", str);
    }

    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        if (trie->child[i] != NULL)
        {
            newStr[size] = i + 'a';
            recursivePrint(trie->child[i], newStr, size + 1);
        }
    }
}

void printTrie(Trie *trie)
{
    if (trie == NULL)
        return;

    recursivePrint(*trie, NULL, 0);
}

void recursiveAutocompleteTrie(Trie trie, char *str, int size, char *prefix)
{
    char newStr[size + 2];
    memcpy(newStr, str, size);
    newStr[size + 1] = 0;

    if (trie->end)
    {
        printf("%s", str);
        for (int i = 0; i < size; ++i)
        {
            printf("%c", str[i]);
        }
        printf("\n");
    }

    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        if (trie->child[i] != NULL)
        {
            newStr[size] = i + 'a';
            recursiveAutocompleteTrie(trie->child[i], newStr, size + 1, prefix);
        }
    }
}
void recursivePrintPre(Trie trie, char *str, int size, char *prefix)
{
    char newStr[size + 2];
    memcpy(newStr, str, size);
    newStr[size + 1] = 0;

    if (trie->end)
    {
        printf("%s%s\n", prefix, str);
    }

    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        if (trie->child[i] != NULL)
        {
            newStr[size] = i + 'a';
            recursivePrintPre(trie->child[i], newStr, size + 1, prefix);
        }
    }
}
void printTriePre(Trie *trie, char *prefix)
{
    if (trie == NULL)
        return;

    recursivePrintPre(*trie, NULL, 0, prefix);
}
void autocompleteTrie(Trie *trie, char *prefix)
{
    if (trie == NULL)
        return;

    Trie node = *trie;

    for (size_t i = 0; i < strlen(prefix); i++)
    {

        node = node->child[prefix[i] - 'a'];
    }

    printTriePre(&node, prefix);
}
