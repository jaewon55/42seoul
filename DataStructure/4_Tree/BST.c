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

static t_BSTNode   *insertPrevSolve(t_BSTNode *node, char key)
{
    if (node == NULL || node->data == key)
        return (NULL);
    if (node->data > key)
    {
        if (node->pLChild)
            return (insertPrevSolve(node->pLChild, key));
        else
            return (node);
    }
    else
    {
        if (node->pRChild)
            return (insertPrevSolve(node->pRChild, key));
        else
            return (node);
    }
}

static t_BSTNode   *deletePrevSolve(t_BSTNode *node, char key)
{
    if (node == NULL || node->data == key)
        return (NULL);
    if (node->data > key)
    {
        if (node->pLChild)
        {
            if (node->pLChild->data == key)
                return (node);
            else
                return (deletePrevSolve(node->pLChild, key));
        }
    }
    else
    {
        if (node->pRChild)
        {
            if (node->pRChild->data == key)
                return (node);
            else
                return (deletePrevSolve(node->pRChild, key));
        }
    }
    return (NULL);
}

static void        delorder(t_BSTNode **node)
{
	t_BSTNode *temp;

	if (*node)
	{
		delorder(&(*node)->pLChild);
		delorder(&(*node)->pRChild);
		temp = *node;
		*node = NULL;
		free(temp);
	}
}

void        deleteBST(t_BST **BST)
{
	if (BST == NULL)
		return ;
	delorder(&((*BST)->root));
	free(*BST);
    *BST = NULL;
}

int         insertNodeBST(t_BST *BST, t_BSTNode newNode)
{
    t_BSTNode   *prevNode;

    if (!BST)
        return (FALSE);
    if (!BST->currenteElementCount)
    {
        BST->root = malloc(sizeof(t_BSTNode));
        *(BST->root) = newNode;
        BST->currenteElementCount++;
        return (TRUE);
    }
    prevNode = insertPrevSolve(BST->root, newNode.data);
    if (!prevNode)
        return (FALSE);
    if (prevNode->data > newNode.data)
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
    BST->currenteElementCount++;
    return (TRUE);
}

t_BSTNode   *deleteNodeBST(t_BST *BST, char key)
{
    t_BSTNode   *prevNode;
    t_BSTNode   *delNode;
    t_BSTNode   *prevMinNode;

    if (!BST)
        return (NULL);
    prevNode = deletePrevSolve(BST->root, key);
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
    BST->currenteElementCount--;
    return (delNode);
}

t_BSTNode   *searchNodeBST(t_BST *BST, char key)
{
    if (!BST)
        return (NULL);
    return (searchSolve(BST->root, key));
}

int         isBSTEmpty(t_BST *BST)
{
    return (BST->currenteElementCount == 0);
}

void    displayBST(t_BSTNode *node)
{
    if (node)
    {
        printf("%c ", node->data);
        displayBST(node->pLChild);
        displayBST(node->pRChild);
    }
}

int main(void)
{
    t_BST   *bst = createBST();
    insertNodeBST(bst, (t_BSTNode){'4', NULL, NULL});
    insertNodeBST(bst, (t_BSTNode){'3', NULL, NULL});
    insertNodeBST(bst, (t_BSTNode){'2', NULL, NULL});
    insertNodeBST(bst, (t_BSTNode){'1', NULL, NULL});
    insertNodeBST(bst, (t_BSTNode){'5', NULL, NULL});
    insertNodeBST(bst, (t_BSTNode){'6', NULL, NULL});
    insertNodeBST(bst, (t_BSTNode){'7', NULL, NULL});
    insertNodeBST(bst, (t_BSTNode){'4', NULL, NULL});
    displayBST(bst->root);
    printf("\n");
    printf("search 5 : %c\n", searchNodeBST(bst, '5')->data);
    deleteNodeBST(bst, '3');
    displayBST(bst->root);
    printf("\n");
    deleteBST(&bst);
    if (!bst)
        printf("good\n");
    system("leaks a.out");
    return 0;
}
