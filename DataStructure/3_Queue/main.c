#include <stdio.h>
#include <stdlib.h>
#include "arrayqueue.h"
#include "linkeddeque.h"

// int main(void)
// {
//     ArrayQueue      *queue;
//     ArrayQueueNode  *first, *second, *third;

//     queue = createArrayQueue(3);
//     printf("createArrayQueue(): %p\n", queue);
//     printf("isArrayQueueFull(): %d\n", isArrayQueueFull(queue));
//     printf("isArrayQueueEmpty(): %d\n", isArrayQueueEmpty(queue));
//     printf("enqueueAQ(): %d\n", enqueueAQ(queue, (ArrayQueueNode){'a'}));
//     printf("isArrayQueueFull(): %d\n", isArrayQueueFull(queue));
//     printf("isArrayQueueEmpty(): %d\n", isArrayQueueEmpty(queue));
//     printf("enqueueAQ(): %d\n", enqueueAQ(queue, (ArrayQueueNode){'b'}));
//     printf("isArrayQueueFull(): %d\n", isArrayQueueFull(queue));
//     printf("isArrayQueueEmpty(): %d\n", isArrayQueueEmpty(queue));
//     printf("enqueueAQ(): %d\n", enqueueAQ(queue, (ArrayQueueNode){'c'}));
//     printf("isArrayQueueFull(): %d\n", isArrayQueueFull(queue));
//     printf("isArrayQueueEmpty(): %d\n", isArrayQueueEmpty(queue));
//     printf("enqueueAQ(): %d\n", enqueueAQ(queue, (ArrayQueueNode){'d'}));
//     printf("isArrayQueueFull(): %d\n", isArrayQueueFull(queue));
//     printf("isArrayQueueEmpty(): %d\n", isArrayQueueEmpty(queue));
//     printf("dequeueAQ(): %p\n", first = dequeueAQ(queue));
//     printf("first->data: %c\n", first->data);
//     printf("isArrayQueueFull(): %d\n", isArrayQueueFull(queue));
//     printf("isArrayQueueEmpty(): %d\n", isArrayQueueEmpty(queue));
//     free(first);
//     printf("dequeueAQ(): %p\n", second = dequeueAQ(queue));
//     printf("second->data: %c\n", second->data);
//     printf("isArrayQueueFull(): %d\n", isArrayQueueFull(queue));
//     printf("isArrayQueueEmpty(): %d\n", isArrayQueueEmpty(queue));
//     free(second);
//     printf("dequeueAQ(): %p\n", third = dequeueAQ(queue));
//     printf("third->data: %c\n", third->data);
//     printf("isArrayQueueFull(): %d\n", isArrayQueueFull(queue));
//     printf("isArrayQueueEmpty(): %d\n", isArrayQueueEmpty(queue));
//     free(third);
//     printf("enqueueAQ(): %d\n", enqueueAQ(queue, (ArrayQueueNode){'d'}));
//     printf("isArrayQueueFull(): %d\n", isArrayQueueFull(queue));
//     printf("isArrayQueueEmpty(): %d\n", isArrayQueueEmpty(queue));
//     printf("dequeueAQ(): %p\n", first = dequeueAQ(queue));
//     printf("first->data: %c\n", first->data);
//     printf("isArrayQueueFull(): %d\n", isArrayQueueFull(queue));
//     printf("isArrayQueueEmpty(): %d\n", isArrayQueueEmpty(queue));
//     free(first);
//     deleteArrayQueue(&queue);
//     system("leaks a.out");
//     return (0);
// }

int main()
{
    LinkedDeque *deque;
    DequeNode   *first, *second, *third;

    deque = createLinkedDeque();
    printf("createLinkedDeque(): %p\n", deque);
    printf("isLinkedDequeEmpty(): %d\n", isLinkedDequeEmpty(deque));
    printf("insertFrontLD(): %d\n", insertFrontLD(deque, (DequeNode){'a', NULL, NULL}));
    printf("isLinkedDequeEmpty(): %d\n", isLinkedDequeEmpty(deque));
    printf("insertFrontLD(): %d\n", insertFrontLD(deque, (DequeNode){'b', NULL, NULL}));
    printf("isLinkedDequeEmpty(): %d\n", isLinkedDequeEmpty(deque));
    printf("insertFrontLD(): %d\n", insertFrontLD(deque, (DequeNode){'c', NULL, NULL}));
    printf("isLinkedDequeEmpty(): %d\n", isLinkedDequeEmpty(deque));
    printf("insertRearLD(): %d\n", insertRearLD(deque, (DequeNode){'d', NULL, NULL}));
    printf("isLinkedDequeEmpty(): %d\n", isLinkedDequeEmpty(deque));
    printf("insertRearLD(): %d\n", insertRearLD(deque, (DequeNode){'e', NULL, NULL}));
    printf("isLinkedDequeEmpty(): %d\n", isLinkedDequeEmpty(deque));
    printf("insertRearLD(): %d\n", insertRearLD(deque, (DequeNode){'f', NULL, NULL}));
    printf("isLinkedDequeEmpty(): %d\n", isLinkedDequeEmpty(deque));
    printf("deleteFrontLD(): %p\n", first = deleteFrontLD(deque));
    printf("deleteFrontLD(): %p\n", second = deleteFrontLD(deque));
    printf("deleteFrontLD(): %p\n", third = deleteFrontLD(deque));
    printf("first: %c\n", first->data);
    free(first);
    printf("second: %c\n", second->data);
    free(second);
    printf("third: %c\n", third->data);
    free(third);
    printf("deleteFrontLD(): %p\n", first = deleteFrontLD(deque));
    printf("deleteFrontLD(): %p\n", second = deleteFrontLD(deque));
    printf("isLinkedDequeEmpty(): %d\n", isLinkedDequeEmpty(deque));
    printf("deleteFrontLD(): %p\n", third = deleteFrontLD(deque));
    printf("first: %c\n", first->data);
    free(first);
    printf("second: %c\n", second->data);
    free(second);
    printf("third: %c\n", third->data);
    free(third);
    printf("isLinkedDequeEmpty(): %d\n", isLinkedDequeEmpty(deque));
    deleteLinkedDeque(&deque);
    system("leaks a.out");
    return (0);
}
