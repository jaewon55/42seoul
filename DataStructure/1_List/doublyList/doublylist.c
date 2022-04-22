#include "doublylist.h"
#include <stdlib.h>
#include <stdio.h>

DoublyList* createDoublyList()
{
	DoublyList* list;
	
	list = (DoublyList*) malloc(sizeof(DoublyList));
	if (list == NULL)
		return (NULL);
	list->currentElementCount = 0;
	list->headerNode.pLLink = NULL;
	list->headerNode.pRLink = NULL;
	return (list);
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	DoublyListNode *newNode;
	DoublyListNode *prevNode;

	if (pList == NULL || position < 0 || pList->currentElementCount < position)
		return (FALSE);
	newNode = (DoublyListNode *)malloc(sizeof(DoublyListNode));
	if (newNode == NULL)
		return (FALSE);
	*newNode = element;
	prevNode = &(pList->headerNode);
	for (int i = 0; i < position; i++)
	{
		prevNode = prevNode->pRLink;
	}
	newNode->pLLink = prevNode;
	newNode->pRLink = prevNode->pRLink;
	prevNode->pRLink = newNode;
	pList->currentElementCount++;
	return (TRUE);
}

int removeDLElement(DoublyList* pList, int position)
{
	DoublyListNode *prevNode;
	DoublyListNode *temp;

	if (pList == NULL || position < 0 || pList->currentElementCount <= position)
		return (FALSE);
	prevNode = &(pList->headerNode);
	for (int i = 0; i < position; i++)
		prevNode = prevNode->pRLink;
	temp = prevNode->pRLink;
	prevNode->pRLink = temp->pRLink;
	if (temp->pRLink)
		temp->pRLink->pLLink = prevNode;
	free(temp);
	temp = NULL;
	pList->currentElementCount--;
	return (TRUE);
}

void clearDoublyList(DoublyList* pList)
{
	if (pList == NULL)
		return ;
	while (removeDLElement(pList, 0))
		;
}

void deleteDoublyList(DoublyList* pList)
{
	if (pList == NULL)
		return ;
	clearDoublyList(pList);
	free(pList);
}

int getDoublyListLength(DoublyList* pList)
{
	if (pList == NULL)
		return (-1);
	return (pList->currentElementCount);
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	DoublyListNode *temp;
	int i;

	if (pList == NULL || position < 0 || pList->currentElementCount <= position)
		return (NULL);
	i = 0;
	temp = &(pList->headerNode);
	while (i < position)
	{
		temp = temp->pRLink;
		i++;
	}
	return (temp->pRLink);
}

void displayDoublyList(DoublyList* pList)
{
	int	position;

	if (pList == NULL)
	{
		printf("DoublyList is NULL\n");
		return ;
	}
	else if (pList->currentElementCount == 0)
	{
		printf("DoublyList is empty\n");
		return ;
	}
	position = 0;
	while (position < pList->currentElementCount)
	{
		printf("DoublyList[%d] : %d\n", position, getDLElement(pList, position)->data);
		position++;
	}
}

void displayDoublyListBack(DoublyList* pList)
{
	int				position;
	DoublyListNode	*temp;

	if (pList == NULL)
	{
		printf("DoublyList is NULL\n");
		return ;
	}
	else if (pList->currentElementCount == 0)
	{
		printf("DoublyList is empty\n");
		return ;
	}
	position = pList->currentElementCount - 1;
	temp = getDLElement(pList, position);
	while (temp->pLLink)
	{
		printf("DoublyList[%d] : %d\n", position, temp->data);
		position--;
		temp = temp->pLLink;
	}
}

// int main(void)
// {
// 	DoublyList *list;

// 	list = createDoublyList();
// 	printf("--- AddTest ---\n");
// 	addDLElement(list, 0, (DoublyListNode){1, NULL, NULL});
// 	addDLElement(list, 1, (DoublyListNode){2, NULL, NULL});
// 	addDLElement(list, 2, (DoublyListNode){3, NULL, NULL});
// 	addDLElement(list, 3, (DoublyListNode){4, NULL, NULL});
// 	addDLElement(list, 4, (DoublyListNode){5, NULL, NULL});
// 	displayDoublyList(list);
// 	printf("------------------------\n");
// 	printf("--- RemoveTest ---\n");
// 	printf("remove result : %d\n", removeDLElement(list, 0));
// 	displayDoublyListBack(list);
// 	printf("------------------------\n");
// 	clearDoublyList(list);
// 	displayDoublyList(list);
// 	deleteDoublyList(list);
// }
