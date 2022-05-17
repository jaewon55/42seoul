#include "BST.h"
#include <stdlib.h>
#include <stdio.h>

t_BST       *createBST()
{
    t_BST   *BST;

    BST = malloc(sizeof(t_BST));
    if (!BST)
        return (NULL);
    BST->currenteElementCount = 0;
    BST->root = NULL;
    return (BST);
}

void        deleteBST(t_BST *BST)
{
	if (BST == NULL)
		return ;
	delorder(&BST->root);
	free(BST);
}

static void        delorder(t_BSTNode **node)
{
	t_BST *temp;

	if (*node)
	{
		delorder(&(*node)->pLChild);
		delorder(&(*node)->pRChild);
		temp = *node;
		*node = NULL;
		free(temp);
	}
}

int         insertNodeBST(t_BST *BST, t_BSTNode newNode)
{
    t_BSTNode   *prevNode;

    if (!BST)
        return (FALSE);
    prevNode = searchPrevSolve(BST->root, newNode.data);
    if (!prevNode)
        return (FALSE);
    if (prevNode->data > key)
    {
        prevNode->pLChild = malloc(sizeof(t_BSTNode));
        if (!prevNode->pLChild)
            return (FALSE);
        *(prevNode->pLChild) = newNode;
    }
    else
    {
        prevNode->pRChild = malloc(sizeof(t_BSTNode));
        if (!prevNode->pRChild)
            return (FALSE);
        *(prevNode->pRChild) = newNode;
    }
    return (TRUE);
}

t_BSTNode   *deleteNodeBST(t_BST *BST, char key)
{
    t_BSTNode   *prevNode;
    t_BSTNode   *delNode;
    t_BSTNode   *prevMinNode;

    if (!BST)
        return (NULL);
    prevNode = searchPrevSolve(BST, key);
    if (!prevNode)
        return (NULL);
    if (prevNode->data > key)
        delNode = prevNode->pLChild;
    else
        delNode = prevNode->pRChild;
    if (delNode->pLChild && delNode->pRChild)
    {
        prevMinNode = searchPrevMinNode(delNode->pRChild);
        if (prevNode->pLChild == delNode)
            prevNode->pLChild = prevMinNode;
        else
            prevNode->pRChild = prevMinNode;
        prevMinNode->pLChild = delNode->pLChild;
        prevMinNode->pRChild = delNode->pRChild;
    }
    else if (delNode->pLChild)
    {
        if (prevNode->pLChild == delNode)
            prevNode->pLChild = delNode->pLChild;
        else
            prevNode->pRChild = delNode->pLChild;
    }
    else if (delNode->pRChild)
    {
        if (prevNode->pLChild == delNode)
            prevNode->pLChild = delNode->pRChild;
        else
            prevNode->pRChild = delNode->pRChild;
    }
    else
    {
        if (prevNode->pLChild == delNode)
            prevNode->pLChild = NULL;
        else
            prevNode->pRChild = NULL;
    }
    delNode->pLChild = NULL;
    delNode->pRChild = NULL;
    return (delNode);
}

static t_BSTNode   *searchPrevMinNode(t_BSTNode *node)
{
    t_BSTNode   *temp;
    t_BSTNode   *temp2;

    temp = node;
    while (temp->pLChild != NULL)
    {
        temp2 = temp;
        temp = temp->pLChild;
    }
    if (temp != node)
        temp2->pLChild = NULL;
    return (temp);
}

t_BSTNode   *searchNodeBST(t_BST *BST, char key)
{
    if (!BST)
        return (NULL);
    return (searchSolve(BST->root, key));
}

static t_BSTNode   *searchSolve(t_BSTNode *node, char key)
{
    if (node == NULL)
        return (NULL);
    if (node->data == key)
        return (node);
    if (node->data > key)
        return (searchSolve(node->pLChild, key));
    return (searchSolve(node->pRChild, key));
}

static t_BSTNode   *searchPrevSolve(t_BSTNode *node, char key)
{
    if (node == NULL || node->data == key)
        return (NULL);
    if (node->data > key)
    {
        if (node->pLChild)
            return (searchPrevSolve(node->pLChild, newNode));
        else
            return (node);
    }
    if (node->data < key)
    {
        if (node->pRChild)
            return (searchPrevSolve(node->pRChild, newNode));
        else
            return (node);
    }
}

int         isBSTEmpty(t_BST *BST)
{
    return (BST->currenteElementCount == 0);
}
