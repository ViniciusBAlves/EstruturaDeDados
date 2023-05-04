#include <stdlib.h>
#include "ABP.h"

TreeNodePtr* createTree()
{
    return NULL;
}

TreeNodePtr* inspectTree(TreeNodePtr *node, int key)
{
    while(node != NULL)
    {
        if(node->info == key)
            return node;
        else if(node->info > key)
            node = node->left;
        else
            node = node->right;
    }

    return NULL;
}

TreeNodePtr* insertTree(TreeNodePtr *node, int info)
{
    if(node == NULL)
    {
        node = (TreeNodePtr*) malloc(sizeof(TreeNodePtr));
        node->info = info;
        node->left = NULL;
        node->right = NULL;
    }
    else if(info < node->info)
        node->left = insertTree(node->left, info);
    else
        node->right = insertTree(node->right, info);

    return node;
}

TreeNodePtr* removeTree(TreeNodePtr *node, int key)
{
    TreeNodePtr *nodeAux = node, *nodeAuxLast = NULL;
    TreeNodePtr *nodeAuxSrc = NULL, *nodeAuxLastSrc = NULL;
    unsigned char sideFlag;

    while((nodeAux != NULL) && (nodeAux->info != key))
    {
        nodeAuxLast = nodeAux;
        if(nodeAux->info > key)
        {
            nodeAux = nodeAux->left;
            sideFlag = 1;
        }
        else
        {
            nodeAux = nodeAux->right;
            sideFlag = 0;
        }
    }
    if(nodeAux == NULL)
        return node;
    else if((nodeAux->left == NULL) && (nodeAux->right == NULL))
    {
        if(sideFlag)
            nodeAuxLast->left = NULL;
        else
            nodeAuxLast->right = NULL;
        free(nodeAux);
    }
    else if((nodeAux->left != NULL) && (nodeAux->right != NULL))
    {
        nodeAuxLastSrc = nodeAuxSrc = nodeAux;
        nodeAuxSrc = nodeAuxSrc->left;
        if(nodeAuxSrc->right == NULL)
        {
            nodeAuxLastSrc->left = NULL;
            nodeAux->info = nodeAuxSrc->info;
            free(nodeAuxSrc);
        }
        else
        {
            while(nodeAuxSrc->right != NULL)
            {
                nodeAuxLastSrc = nodeAuxSrc;
                nodeAuxSrc = nodeAuxSrc->right;
            }
            nodeAuxLastSrc->right = NULL;
            nodeAux->info = nodeAuxSrc->info;
            free(nodeAuxSrc);
        }
    }
    else
    {
        if(sideFlag)
        {
            if(nodeAux->left == NULL)
                nodeAuxLast->left = nodeAux->right;
            else
                nodeAuxLast->left = nodeAux->left;
        }
        else
        {
            if(nodeAux->left == NULL)
                nodeAuxLast->right = nodeAux->right;
            else
                nodeAuxLast->right = nodeAux->left;
        }
        free(nodeAux);
    }

    return node;
}

void printTree(TreeNodePtr *node, int mode)
{
    if(node != NULL)
    {
        switch(mode)
        {
        case LEFT_PREFIXED:
            printf("%d ", node->info);
            printTree(node->left, mode);
            printTree(node->right, mode);
            break;
        case RIGHT_PREFIXED:
            printf("%d ", node->info);
            printTree(node->right, mode);
            printTree(node->left, mode);
            break;
        case LEFT_CENTRAL:
            printTree(node->left, mode);
            printf("%d ", node->info);
            printTree(node->right, mode);
            break;
        case RIGHT_CENTRAL:
            printTree(node->right, mode);
            printf("%d ", node->info);
            printTree(node->left, mode);
            break;
        case LEFT_POSTFIXED:
            printTree(node->left, mode);
            printTree(node->right, mode);
            printf("%d ", node->info);
            break;
        case RIGHT_POSTFIXED:
            printTree(node->right, mode);
            printTree(node->left, mode);
            printf("%d ", node->info);
            break;
        default:
            printTree(node->left, mode);
            printf("%d ", node->info);
            printTree(node->right, mode);
            break;
        }
    }
}
