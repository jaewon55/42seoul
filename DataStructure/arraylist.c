#include "arraylist.h"
#include <stdlib.h>
#include <stdio.h>

ArrayList* createArrayList(int maxElementCount)
{
	ArrayList		*arrayList;
	ArrayListNode	*node;

	arrayList = malloc(sizeof(ArrayList) * 1);
	if (!arrayList)
		return (NULL);
	node = malloc(sizeof(ArrayListNode) * maxElementCount);
	if (!node)
	{
		free(arrayList);
		return (NULL);
	}
	arrayList->pElement = node;
	arrayList->maxElementCount = maxElementCount;
	arrayList->currentElementCount = 0;
	return (arrayList);
}

void deleteArrayList(ArrayList* pList)
{
	if (pList != NULL)
	{
		free(pList->pElement);
		free(pList);
	}
}

int isArrayListFull(ArrayList* pList)
{
	if (pList->maxElementCount == pList->currentElementCount)
		return (TRUE);
	else
		return (FALSE);
}

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	int	index;

	if (pList == NULL || isArrayListFull(pList) \
	|| position < 0 ||  pList->currentElementCount < position)
		return (FALSE);
	index = pList->currentElementCount - 1;
	while (index >= position)
	{
		pList->pElement[index + 1] = pList->pElement[index];
		index--;
	}
	pList->pElement[position] = element;
	pList->currentElementCount++;
	return (TRUE);
}

int removeALElement(ArrayList* pList, int position)
{
	if (pList == NULL || position < 0 || pList->currentElementCount <= position)
		return (FALSE);
	while (position < pList->currentElementCount - 1)
	{
		pList->pElement[position] = pList->pElement[position + 1];
		position++;
	}
	pList->currentElementCount--;
	return (TRUE);
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	if (pList == NULL || pList->currentElementCount <= position)
		return (NULL);
	return (&(pList->pElement[position]));
}

void displayArrayList(ArrayList* pList)
{
	int	position;

	if (pList == NULL)
	{
		printf("ArrayList is NULL\n");
		return ;
	}
	else if (pList->currentElementCount == 0)
	{
		printf("ArrayList is empty\n");
		return ;
	}
	position = 0;
	while (position < pList->currentElementCount)
	{
		printf("ArrayList[%d] : %d\n", position, getALElement(pList, position)->data);
		position++;
	}
}

void clearArrayList(ArrayList* pList)
{
	if (pList == NULL)
		return ;
	pList->currentElementCount = 0;
}

int getArrayListLength(ArrayList* pList)
{
	if (pList == NULL)
		return (-1);
	return (pList->currentElementCount);
}

int main(void)
{
	ArrayList *ar = createArrayList(5);
	ArrayListNode node1;
	node1.data = 10;
	printf("addALE position 1 : %d\n", addALElement(ar, 1, node1));
	printf("addALE position 0 : %d\n", addALElement(ar, 0, node1));
	displayArrayList(ar);
	printf("removeALE position 1 : %d\n", removeALElement(ar, 1));
	printf("removeALE position 0 : %d\n", removeALElement(ar, 0));
	displayArrayList(ar);
	addALElement(ar, 0, node1);
	addALElement(ar, 1, node1);
	addALElement(ar, 2, node1);
	addALElement(ar, 3, node1);
	addALElement(ar, 4, node1);
	printf("isFull : %d\n", isArrayListFull(ar));
	printf("addALE position 0 : %d\n", addALElement(ar, 0, node1));
	displayArrayList(ar);
	ArrayListNode *node = getALElement(ar, 0);
	node->data = 30;
	printf("%d\n", getALElement(ar, 0)->data);
	printf("removeALE position 2 : %d\n", removeALElement(ar, 2));
	printf("removeALE position 2 : %d\n", removeALElement(ar, 2));
	printf("removeALE position 2 : %d\n", removeALElement(ar, 2));
	printf("removeALE position 2 : %d\n", removeALElement(ar, 2));
	displayArrayList(ar);
	deleteArrayList(ar);
	ar = NULL;
	displayArrayList(ar);
	return (0);
}