#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

LinkedList* createLinkedList()
{
	LinkedList *newList;

	newList = (LinkedList *)malloc(sizeof(LinkedList));
	if (newList == NULL)
		return (NULL);
	newList->currentElementCount = 0;
	newList->headerNode.pLink = NULL;
	return (newList);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode	*newNode;
	ListNode	*prevNode;
	int			i;
	
	if (pList == NULL || position < 0 ||  pList->currentElementCount < position)
		return (FALSE);
	newNode = (ListNode *)malloc(sizeof(ListNode));
	if (newNode == NULL)
		return (FALSE);
	*newNode = element;
	prevNode = &(pList->headerNode);
	i = 0;
	while (i < position)
	{
		prevNode = prevNode->pLink;
		i++;
	}
	newNode->pLink = prevNode->pLink;
	prevNode->pLink = newNode;
	pList->currentElementCount++;
	return (TRUE);
}

int removeLLElement(LinkedList* pList, int position)
{
	ListNode	*prevNode;
	ListNode	*nodeToDelete;
	int			i;

	if (pList == NULL || position < 0 || pList->currentElementCount <= position)
		return (FALSE);
	prevNode = &(pList->headerNode);
	i = 0;
	while (i < position)
	{
		prevNode = prevNode->pLink;
		i++;
	}
	nodeToDelete = prevNode->pLink;
	prevNode->pLink = nodeToDelete->pLink;
	free(nodeToDelete);
	pList->currentElementCount--;
	return (TRUE);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode	*temp;
	int			i;

	if (pList == NULL || position < 0 || pList->currentElementCount <= position)
		return (NULL);
	i = 0;
	temp = &(pList->headerNode);
	while (i < position)
	{
		temp = temp->pLink;
		i++;
	}
	return (temp->pLink);
}

void clearLinkedList(LinkedList* pList)
{
	if (pList == NULL)
		return ;
	while (removeLLElement(pList, 0))
		;
}

int getLinkedListLength(LinkedList* pList)
{
	if (pList == NULL)
		return (-1);
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
	if (pList == NULL)
		return ;
	clearLinkedList(pList);
	free(pList);
}

void displayLinkedList(LinkedList* pList)
{
	int	position;

	if (pList == NULL)
	{
		printf("LinkedList is NULL\n");
		return ;
	}
	else if (pList->currentElementCount == 0)
	{
		printf("LinkedList is empty\n");
		return ;
	}
	position = 0;
	while (position < pList->currentElementCount)
	{
		printf("ArrayList[%d] : %d\n", position, getLLElement(pList, position)->data);
		position++;
	}
}

int main(void)
{
	ListNode node;
	node.data = 10;
	node.pLink = NULL;
	LinkedList *list = createLinkedList();
	printf("insert result: %d\n", addLLElement(list, 0, node));
	node.data = 20;
	printf("insert result: %d\n", addLLElement(list, 1, node));
	displayLinkedList(list);
	printf("value : %d\n", getLLElement(list, 0)->data);
	printf("value : %d\n", getLLElement(list, 1)->data);
	printf("remove result: %d\n", removeLLElement(list, 0));
	displayLinkedList(list);
	printf("value : %d\n", getLLElement(list, 0)->data);
	deleteLinkedList(list);
}