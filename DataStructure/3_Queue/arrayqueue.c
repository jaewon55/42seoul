#include <stdlib.h>
#include "arrayqueue.h"

ArrayQueue* createArrayQueue(int maxElementCount)
{
    ArrayQueue  *queue;

    if (maxElementCount <= 0)
        return (NULL);
    queue = malloc(sizeof(ArrayQueue));
    if (!queue)
        return (NULL);
    queue->pElement = malloc(sizeof(ArrayQueueNode) * maxElementCount);
    if (!queue->pElement)
    {
        free(queue);
        return (NULL);
    }
    queue->maxElementCount = maxElementCount;
    queue->currentElementCount = 0;
    queue->front = 0;
    queue->rear = 0;
    return (queue);
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
    if (!pQueue)
        return (ERROR);
    if (isArrayQueueFull(pQueue))
        return (FALSE);
    pQueue->pElement[pQueue->rear] = element;
    pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
    pQueue->currentElementCount++;
    return (TRUE);
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
    ArrayQueueNode  *dequeue;

    if (!pQueue || isArrayQueueEmpty(pQueue))
        return (NULL);
    dequeue = malloc(sizeof(ArrayQueueNode));
    if (!dequeue)
        return (NULL);
    *dequeue = pQueue->pElement[pQueue->front];
    pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
    pQueue->currentElementCount--;
    return (dequeue);
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
    if (!pQueue || isArrayQueueEmpty(pQueue))
        return (NULL);
    return (&(pQueue->pElement[pQueue->front]));
}

void deleteArrayQueue(ArrayQueue** pQueue)
{
    if (!pQueue || !*pQueue)
        return ;
    free((*pQueue)->pElement);
    free(*pQueue);
    *pQueue = NULL;
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
    if (!pQueue)
        return (ERROR);
    if (pQueue->maxElementCount == pQueue->currentElementCount)
        return (TRUE);
    return (FALSE);
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
    if (!pQueue)
        return (ERROR);
    if (!pQueue->currentElementCount)
        return (TRUE);
    return (FALSE);
}
