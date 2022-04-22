#include "arraylist.h"
#include <stdlib.h>
#include <stdio.h>

ArrayList* createArrayList(int maxElementCount)
{
	ArrayList		*arrayList;
	ArrayListNode	*node;

	if (maxElementCount <= 0)
		return (NULL);
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
	if (pList && pList->maxElementCount == pList->currentElementCount)
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

void	print_line(char *str)
{
	char *line = "----------";
	printf("%s%s%s\n", line, str, line);
}

// int main(void)
// {
// 	ArrayList *ar;
// 	ArrayListNode node1;
// 	ArrayListNode node2;
// 	ArrayListNode node3;
// 	ArrayListNode node4;
// 	ArrayListNode node5;

// 	node1.data = 10;
// 	node2.data = 20;
// 	node3.data = 30;
// 	node4.data = 40;
// 	node5.data = 50;
// 	ar = createArrayList(5);

// 	print_line("Add Test");
// 	displayArrayList(ar);
// 	printf("addALE position 1 : %d\n", addALElement(ar, 1, node1));
// 	printf("addALE position 0 : %d\n", addALElement(ar, 0, node1));
// 	displayArrayList(ar);
// 	printf("\n\n");

// 	print_line("Remove Test");
// 	displayArrayList(ar);
// 	printf("removeALE position 1 : %d\n", removeALElement(ar, 1));
// 	printf("removeALE position 0 : %d\n", removeALElement(ar, 0));
// 	displayArrayList(ar);
// 	printf("\n\n");

// 	print_line("IsFull Test");
// 	displayArrayList(ar);
// 	printf("isFull : %d\n", isArrayListFull(ar));
// 	addALElement(ar, 0, node5);
// 	addALElement(ar, 0, node4);
// 	addALElement(ar, 0, node3);
// 	addALElement(ar, 0, node2);
// 	addALElement(ar, 0, node1);
// 	printf("\n\nadd all element\n\n");
// 	displayArrayList(ar);
// 	printf("isFull : %d\n", isArrayListFull(ar));
// 	printf("addALE position 0 : %d\n", addALElement(ar, 0, node1));
// 	printf("\n\n");

// 	print_line("GetElement Test");
// 	addALElement(ar, 0, node1);
// 	displayArrayList(ar);
// 	ArrayListNode *tmp_node = getALElement(ar, 0);
// 	tmp_node->data = -10;
// 	printf("\nchange value\n\n");
// 	displayArrayList(ar);
// 	printf("\n\n");

// 	print_line("Clear Test");
// 	displayArrayList(ar);
// 	clearArrayList(ar);
// 	printf("\nafter clear\n\n");
// 	displayArrayList(ar);
// 	printf("\n\n");

// 	print_line("Delete Test");
// 	displayArrayList(ar);
// 	deleteArrayList(ar);
// 	ar = NULL;
// 	printf("\nafter delete\n\n");
// 	displayArrayList(ar);
// 	printf("\n\n");
// 	return (0);
// }
