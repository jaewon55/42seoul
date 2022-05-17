#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

t_heap      *createHeap(int maxElementSize, int (*compare) (char, char))
{
    t_heap *heap;

    heap = malloc(sizeof(t_heap));
    if (!heap)
        return (NULL);
    heap->arrayHeap = malloc(sizeof(t_heapNode) * (maxElementSize + 1));
    if (!heap->arrayHeap)
    {
        free(heap);
        return (NULL);
    }
    heap->maxElementSize = maxElementSize;
    heap->currentElementCount = 0;
    heap->compare = compare;
    return (heap);
}

int pushHeap(t_heap *heap, t_heapNode heapNode)
{
    int i;

    if (heap == NULL || isHeapFull(heap))
        return (FALSE);
    heap->currentElementCount += 1;
    i = heap->currentElementCount;
    while ((i != 1) && (heap->compare(heapNode.data, heap->arrayHeap[i/2]->data)))
    {
        heap->arrayHeap[i] = heap->arrayHeap[i/2];
        i = i / 2;
    }
    heap->arrayHeap[i] = heapNode;
    return (TRUE);
}

t_heapNode  popHeap(t_heap *heap)
{
    t_heapNode  result;
    t_heapNode  temp;
    int         parent;
    int         child;

    if (heap == NULL || isHeapEmpty(heap))
        return (FALSE);
    result = heap->arrayHeap[1];
    temp = heap->arrayHeap[heap->currentElementCount];
    heap->currentElementCount -= 1;
    parent = 1;
    child = 2;
    while(child <= heap->currentElementCount) // 마지막 노드
    {
        if ((child < heap->currentElementCount)\
        && heap->compare(heap->arrayHeap[child + 1].data, heap->arrayHeap[child].data))
            child = child + 1;
        if (!heap->compare(heap->arrayHeap[child].data, temp->data))
            break;
        heap->arrayHeap[parent] = heap->arrayHeap[child]
        parent = child;
        child = child * 2;
    }
    heap->arrayHeap[parent] = temp;
    return (result);
}

t_heapNode  peekHeap(t_heap *heap)
{
    return (heap->arrayHeap[1]);
}

void        deleteHeap(t_heap **heap)
{
    if (*heap == NULL)
        return ;
    free(*heap->arrayHeap);
    free(*heap);
    *heap == NULL;
}

int         isHeapFull(t_heap *heap)
{
    return (heap->currentElementCount == heap->maxElementSize);
}

int         isHeapEmpty(t_heap *heap)
{
    return (heap->currentElementCount == 0);
}

int         isFullBinTree(t_heap *heap)
{
    int i = 2;

    while (i - 1 < heap->currentElementCount)
    {
        if (i - 1 == heap->currentElementCount)
            return (TRUE);
        i *= 2;
    }
    return (FALSE);
}

int         maxHeapCompare(char data1, char data2)
{
    return (data1 > data2);
}

int         minHeapCompare(char data1, char data2)
{
    return (data1 < data2);
}

int main(void)
{

    return (0);
}