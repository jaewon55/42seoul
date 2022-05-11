#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

// 중위
void inorder(BinTreeNode *node)
{
	if (node)
	{
		inorder(node->pLeftChild);
		printf("%c", node->data);
		inorder(node->pRightChild);
	}
}

// 전위
void preorder(BinTreeNode *node)
{
	if (node)
	{
		printf("%c", node->data);
		preorder(node->pLeftChild);
		preorder(node->pRightChild);
	}
}

// 후위
void postorder(BinTreeNode *node)
{
	if (node)
	{
		postorder(node->pLeftChild);
		postorder(node->pRightChild);
		printf("%c", node->data);
	}
}

int main()
{
	BinTree		*binTree;
	BinTreeNode	*left;
	BinTreeNode	*right;

	binTree = makeBinTree((BinTreeNode){'+', 0, NULL, NULL});
	left = insertLeftChildNodeBT(binTree->pRootNode, (BinTreeNode){'*', 0, NULL, NULL});
	insertRightChildNodeBT(binTree->pRootNode, (BinTreeNode){'E', 0, NULL, NULL});
	insertRightChildNodeBT(left, (BinTreeNode){'D', 0, NULL, NULL});
	left = insertLeftChildNodeBT(left, (BinTreeNode){'*', 0, NULL, NULL});
	insertRightChildNodeBT(left, (BinTreeNode){'C', 0, NULL, NULL});
	left = insertLeftChildNodeBT(left, (BinTreeNode){'/', 0, NULL, NULL});
	insertRightChildNodeBT(left, (BinTreeNode){'B', 0, NULL, NULL});
	insertLeftChildNodeBT(left, (BinTreeNode){'A', 0, NULL, NULL});
	displayTree(binTree->pRootNode);
	printf("inorder : ");
	inorder(binTree->pRootNode);
	printf("\n");
	printf("preorder : ");
	preorder(binTree->pRootNode);
	printf("\n");
	printf("postorder : ");
	postorder(binTree->pRootNode);
	printf("\n");
	deleteBinTree(binTree);
	return (0);
}