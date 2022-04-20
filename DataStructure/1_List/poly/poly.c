#include "poly.h"
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
	
	if (pList == NULL || position < 0 || pList->currentElementCount < position)
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
		printf("PolyList is NULL\n");
		return ;
	}
	else if (pList->currentElementCount == 0)
	{
		printf("PolyList is empty\n");
		return ;
	}
	position = 0;
	while (position < pList->currentElementCount)
	{
		printf("PolyList[%d] : coef: %d | degree: %d\n", position, \
		getLLElement(pList, position)->coef, getLLElement(pList, position)->degree);
		position++;
	}
}

int	addElementToPoly(LinkedList *poly, ListNode element)
{
	ListNode	*curr;
	int			position;

	if (poly == NULL)
		return (FALSE);
	position = 0;
	curr = poly->headerNode.pLink;
	while (curr != NULL)
	{
		if (element.degree > curr->degree)
			break ;
		if (element.degree == curr->degree)
		{
			curr->coef += element.coef;
			return (TRUE);
		}
		position++;
		curr = curr->pLink;
	}
	return (addLLElement(poly, position, element));
}

LinkedList	*addPolyList(LinkedList *poly1, LinkedList *poly2)
{
	LinkedList	*result;
	ListNode	*temp;

	if (poly1 == NULL || poly2 == NULL)
		return (NULL);
	result = createLinkedList();
	if (result == NULL)
		return (NULL);
	temp = poly1->headerNode.pLink;
	while (temp)
	{
		addElementToPoly(result, *temp);
		temp = temp->pLink;
	}
	temp = poly2->headerNode.pLink;
	while (temp)
	{
		addElementToPoly(result, *temp);
		temp = temp->pLink;
	}
	return (result);
}

int	main()
{
	LinkedList	*poly1;
	LinkedList	*poly2;

	poly1 = createLinkedList();
	poly2 = createLinkedList();
	addElementToPoly(poly1, (ListNode){3, 3, NULL});
	addElementToPoly(poly1, (ListNode){1, 1, NULL});
	addElementToPoly(poly1, (ListNode){2, 2, NULL});
	addElementToPoly(poly1, (ListNode){2, 0, NULL});
	displayLinkedList(poly1);
	printf("---------------------------\n");
	addElementToPoly(poly2, (ListNode){7, 3, NULL});
	addElementToPoly(poly2, (ListNode){9, 1, NULL});
	addElementToPoly(poly2, (ListNode){8, 2, NULL});
	addElementToPoly(poly2, (ListNode){8, 4, NULL});
	displayLinkedList(poly2);
	printf("---------------------------\n");
	LinkedList	*result = addPolyList(poly1, poly2);
	displayLinkedList(result);
	return (0);
}
