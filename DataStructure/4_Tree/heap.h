#ifndef HEAP_H
# define HEAP_H

typedef struct  s_heapNode
{
                char data;
}               t_heapNode;

typedef struct  s_heap
{
    t_heapNode  *arrayHeap;
    int         (*compare) (char, char);
    int         maxElementSize;
    int         currentElementCount;
}               t_heap;

t_heap      *createHeap(int maxElementSize, int (*compare) (char, char));
int         pushHeap(t_heap *heap, t_heapNode heapNode);
t_heapNode  popHeap(t_heap *heap);
t_heapNode  peekHeap(t_heap *heap);
void        deleteHeap(t_heap **heap);
int         isHeapFull(t_heap *heap);
int         isHeapEmpty(t_heap *heap);
int         isFullBinTree(t_heap *heap);
int         maxHeapCompare(char data1, char data2);
int         minHeapCompare(char data1, char data2);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif
