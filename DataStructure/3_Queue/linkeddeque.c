#include <stdlib.h>
#include "linkeddeque.h"

LinkedDeque*    createLinkedDeque()
{
    LinkedDeque *deque;

    deque = malloc(sizeof(LinkedDeque));
    if (!deque)
        return (NULL);
    deque->currentElementCount = 0;
    deque->pFrontNode = NULL;
    deque->pRearNode = NULL;
    return (deque);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
    DequeNode   *newNode;

    if (!pDeque)
        return (ERROR);
    newNode = malloc(sizeof(DequeNode));
    if (!newNode)
        return (FALSE);
    newNode->data = element.data;
    newNode->pLLink = NULL;
    if (isLinkedDequeEmpty(pDeque))
    {
        pDeque->pFrontNode = newNode;
        pDeque->pRearNode = newNode;
        newNode->pRLink = NULL;
    }
    else
    {
        newNode->pRLink = pDeque->pFrontNode;
        pDeque->pFrontNode->pLLink = newNode;
        pDeque->pFrontNode = newNode;
    }
    pDeque->currentElementCount++;
    return (TRUE);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
    DequeNode   *newNode;

    if (!pDeque)
        return (ERROR);
    newNode = malloc(sizeof(DequeNode));
    if (!newNode)
        return (FALSE);
    newNode->data = element.data;
    newNode->pRLink = NULL;
    if (isLinkedDequeEmpty(pDeque))
    {
        pDeque->pFrontNode = newNode;
        pDeque->pRearNode = newNode;
        newNode->pLLink = NULL;
    }
    else
    {
        newNode->pLLink = pDeque->pRearNode;
        pDeque->pRearNode->pRLink = newNode;
        pDeque->pRearNode = newNode;
    }
    pDeque->currentElementCount++;
    return (TRUE);
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
    DequeNode   *delNode;

    if (!pDeque || isLinkedDequeEmpty(pDeque))
        return (NULL);
    delNode = pDeque->pFrontNode;
    pDeque->pFrontNode = delNode->pRLink;
    if (pDeque->pFrontNode)
        pDeque->pFrontNode->pLLink = NULL;
    delNode->pRLink = NULL;
    pDeque->currentElementCount--;
    return (delNode);
}

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
    DequeNode   *delNode;

    if (!pDeque || isLinkedDequeEmpty(pDeque))
        return (NULL);
    delNode = pDeque->pRearNode;
    pDeque->pRearNode = delNode->pLLink;
    if (pDeque->pRearNode)
        pDeque->pRearNode->pRLink = NULL;
    delNode->pLLink = NULL;
    pDeque->currentElementCount--;
    return (delNode);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
    if (!pDeque)
        return (NULL);
    return (pDeque->pFrontNode);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
    if (!pDeque)
        return (NULL);
    return (pDeque->pRearNode);
}

void    deleteLinkedDeque(LinkedDeque** pDeque)
{
    DequeNode   *delNode;

    if (!pDeque || !*pDeque)
        return ;
    while (!isLinkedDequeEmpty(*pDeque))
    {
        delNode = deleteFrontLD(*pDeque);
        free(delNode);
    }
    free(*pDeque);
    *pDeque = NULL;
}

int isLinkedDequeFull(LinkedDeque* pDeque)
{
    if (!pDeque)
        return (ERROR);
    return (FALSE);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
    if (!pDeque)
        return (ERROR);
    if (pDeque->currentElementCount == 0)
        return (TRUE);
    return (FALSE);
}