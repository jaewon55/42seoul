#include "circularlist.h"
#include <stdlib.h>
#include <stdio.h>

CircularList* createCircularList()
{
	CircularList	*list;
	
	list = (CircularList*)malloc(sizeof(CircularList));
	if (list == NULL)
		return (NULL);
	list->currentElementCount = 0;
	list->headerNode.pLink = NULL;
	return (list);
}

CircularListNode* getCLElement(CircularList* pList, int position)
{
	CircularListNode	*prevNode;
	int					i;
	
	if (pList == NULL || position < 0 || pList->currentElementCount <= position)
		return (NULL);
	prevNode = &(pList->headerNode);
	i = 0;
	while (i < position)
	{
		prevNode = prevNode->pLink;
		i++;
	}
	return (prevNode->pLink);
}

CircularListNode* getCLLastElement(CircularList* pList)
{
	return (getCLElement(pList, pList->currentElementCount - 1));
}

int addCLElement(CircularList* pList, int position, CircularListNode element)
{
	CircularListNode	*newNode;
	CircularListNode	*prevNode;
	CircularListNode	*lastNode;

	if (pList == NULL || position < 0 || pList->currentElementCount < position)
		return (FALSE);
	newNode = (CircularListNode	*)malloc(sizeof(CircularListNode));
	if (newNode == NULL)
		return (FALSE);
	*newNode = element;
	if (pList->headerNode.pLink == NULL)
	{
		pList->headerNode.pLink = newNode;
		newNode->pLink = newNode;
		pList->currentElementCount++;
	}
	else if (position == 0)
	{
		newNode->pLink = pList->headerNode.pLink;
		pList->headerNode.pLink = newNode;
		pList->currentElementCount++;
		lastNode = getCLLastElement(pList);
		lastNode->pLink = newNode;
	}
	else
	{
		prevNode = &(pList->headerNode);
		for (int i = 0; i < position; i++)
			prevNode = prevNode->pLink;
		newNode->pLink = prevNode->pLink;
		prevNode->pLink = newNode;
		pList->currentElementCount++;
	}
	return (TRUE);
}

int removeCLElement(CircularList* pList, int position)
{
	CircularListNode	*prevNode;
	CircularListNode	*temp;

	if (pList == NULL || position < 0 || pList->currentElementCount <= position)
		return (FALSE);
	prevNode = &(pList->headerNode);
	for (int i = 0; i < position; i++)
		prevNode = prevNode->pLink;
	temp = prevNode->pLink;
	prevNode->pLink = temp->pLink;
	free(temp);
	pList->currentElementCount--;
	if (pList->currentElementCount == 0)
		pList->headerNode.pLink = NULL;
	else if (position == 0)
		getCLLastElement(pList)->pLink = pList->headerNode.pLink;
	return (TRUE);
}

void clearCircularList(CircularList* pList)
{
	if (pList == NULL)
		return ;
	while (removeCLElement(pList, 0))
		;
}

void deleteCircularList(CircularList* pList)
{
	if (pList == NULL)
		return ;
	clearCircularList(pList);
	free(pList);
}

int getCircularListLength(CircularList* pList)
{
	if (pList == NULL)
		return (-1);
	return (pList->currentElementCount);
}

void displayCircularList(CircularList* pList)
{
	int	position;

	if (pList == NULL)
	{
		printf("CircularList is NULL\n");
		return ;
	}
	else if (pList->currentElementCount == 0)
	{
		printf("CircularList is empty\n");
		return ;
	}
	position = 0;
	while (position < pList->currentElementCount)
	{
		printf("CircularList[%d] : %d\n", position, getCLElement(pList, position)->data);
		position++;
	}
}

int main(void)
{
	CircularList	*list;

	list = createCircularList();
	printf("--- AddTest ---\n");
	addCLElement(list, 0, (CircularListNode){1, NULL});
	addCLElement(list, 1, (CircularListNode){2, NULL});
	addCLElement(list, 2, (CircularListNode){3, NULL});
	addCLElement(list, 3, (CircularListNode){4, NULL});
	addCLElement(list, 4, (CircularListNode){5, NULL});
	displayCircularList(list);
	printf("------------------------\n");
	printf("--- RemoveTest ---\n");
	printf("remove result : %d\n", removeCLElement(list, 0));
	displayCircularList(list);
	printf("------------------------\n");
	clearCircularList(list);
	displayCircularList(list);
	deleteCircularList(list);
}
