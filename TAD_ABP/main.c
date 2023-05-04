#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"

int main()
{
    TreeNodePtr *tree;
    int i, num;
    int info;

    tree = createTree();

    printf("Insira o valor de nodos desejado: ");
    scanf("%d", &num);
    printf("\n");
    for(i = 0; i < num; i++)
    {
        printf("Insira o valor do nodo desejado: ");
        scanf("%d", &info);
        tree = insertTree(tree, info);
    }
    printf("\n");
    printTree(tree, LEFT_CENTRAL);
    printf("\n");

    printf("\n");
    printf("Insira o valor do nodo a ser removido: ");
    scanf("%d", &info);
    tree = removeTree(tree, info);

    printf("\n");
    printTree(tree, LEFT_CENTRAL);
    printf("\n");

    return 0;
}
