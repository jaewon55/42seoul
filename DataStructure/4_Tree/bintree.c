#include "bintree.h"
#include <stdlib.h>
#include <stdio.h>

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree *bintree;
	BinTreeNode *bintreenode;

	bintree = malloc(sizeof(BinTree));
	if (bintree == NULL)
		return (NULL);
	bintreenode = malloc(sizeof(BinTreeNode));
	if (bintreenode == NULL)
	{
		free(bintree);
		return (NULL);
	}
	*bintreenode = rootNode;
	bintree->pRootNode = bintreenode;
	return (bintree);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	if (pBinTree == NULL)
		return (NULL);
	return (pBinTree->pRootNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	if (pParentNode == NULL)
		return (NULL);
	if (pParentNode->pLeftChild == NULL)
	{
		pParentNode->pLeftChild = malloc(sizeof(BinTreeNode));
		if (pParentNode->pLeftChild == NULL)
			return (NULL);
		*pParentNode->pLeftChild = element;
	}
	return (pParentNode->pLeftChild);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	if (pParentNode == NULL)
		return (NULL);
	if (pParentNode->pRightChild == NULL)
	{
		pParentNode->pRightChild = malloc(sizeof(BinTreeNode));
		if (pParentNode->pRightChild == NULL)
			return (NULL);
		*pParentNode->pRightChild = element;
	}
	return (pParentNode->pRightChild);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (pNode == NULL)
		return (NULL);
	return (pNode->pLeftChild);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	if (pNode == NULL)
		return (NULL);
	return (pNode->pRightChild);
}

static void delorder(BinTreeNode **node)
{
	BinTreeNode *temp;
	if (*node)
	{
		delorder(&(*node)->pLeftChild);
		delorder(&(*node)->pRightChild);
		temp = *node;
		*node = NULL;
		free(temp);
	}
}

void displayTree(BinTreeNode *node)
{
	if (node)
	{
		printf("%c\n", node->data);
		displayTree(node->pLeftChild);
		displayTree(node->pRightChild);
	}
}

void deleteBinTree(BinTree* pBinTree)
{
	if (pBinTree == NULL)
		return ;
	delorder(&pBinTree->pRootNode);
	free(pBinTree);
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
	if (pNode != NULL)
		free(pNode);
}

// int	main(void)
// {

// 	BinTree 	*bintree;
// 	char		data = 'A';
// 	BinTreeNode	*left;
// 	BinTreeNode	*right;

// 	bintree = makeBinTree((BinTreeNode){data++, 0, NULL, NULL});
// 	left = insertLeftChildNodeBT(bintree->pRootNode, (BinTreeNode){data++, 0, NULL, NULL});
// 	right = insertRightChildNodeBT(bintree->pRootNode, (BinTreeNode){data++, 0, NULL, NULL});
// 	insertLeftChildNodeBT(left, (BinTreeNode){data++, 0, NULL, NULL});
// 	insertRightChildNodeBT(left, (BinTreeNode){data++, 0, NULL, NULL});
// 	insertLeftChildNodeBT(right, (BinTreeNode){data++, 0, NULL, NULL});
// 	insertRightChildNodeBT(right, (BinTreeNode){data++, 0, NULL, NULL});
// 	displayTree(bintree->pRootNode);
// 	deleteBinTree(bintree);
// 	system("leaks a.out");
// 	return (0);
// }