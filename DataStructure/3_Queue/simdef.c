#include <stdio.h>
#include <stdlib.h>
#include "arrayqueue.h"
#include "simdef.h"
#define N 5
#define T_CLOSE 14

void insertCustomer(int arrivalTime, int processTime, ArrayQueue *pQueue)
{
	SimCustomer	*newCustomer;

	newCustomer = malloc(sizeof(SimCustomer));
	if (!newCustomer)
		exit(1);
	newCustomer->arrivalTime = arrivalTime;
	newCustomer->serviceTime = processTime;
	newCustomer->startTime = 0;
	newCustomer->endTime = processTime;
	enqueueAQ(pQueue, (ArrayQueueNode){newCustomer});
}

void processArrival(int currentTime, ArrayQueue *pArrivalQueue, ArrayQueue *pWaitQueue)
{
	ArrayQueueNode	*chair;
	SimCustomer		*customer;
	SimCustomer		*nextC;

	chair = peekAQ(pArrivalQueue);
	if (!chair)
		return ;
	customer = chair->data;
	if (currentTime != customer->arrivalTime)
		return ;
	free(dequeueAQ(pArrivalQueue));
	chair = NULL;
	chair = peekAQ(pArrivalQueue);
	if (chair)
	{
		nextC = chair->data;
		if (nextC->arrivalTime > customer->endTime)
			nextC->startTime = nextC->arrivalTime;
		else
			nextC->startTime = customer->endTime;
		nextC->endTime = nextC->startTime + nextC->serviceTime;
	}
	enqueueAQ(pWaitQueue, (ArrayQueueNode){customer});
}

ArrayQueueNode* processServiceNodeEnd(int currentTime, ArrayQueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
	SimCustomer	*customer;

	if (!pServiceNode)
		return (NULL);
	customer = pServiceNode->data;
	if (!customer || currentTime != customer->endTime)
		return (NULL);
	(*pServiceUserCount)++;
	*pTotalWaitTime += customer->startTime - customer->arrivalTime;
	free(customer);
	pServiceNode->data = NULL;
	return (pServiceNode);
}

ArrayQueueNode* processServiceNodeStart(int currentTime, ArrayQueue *pWaitQueue)
{
	ArrayQueueNode	*chair;

	chair = peekAQ(pWaitQueue);
	if (!chair)
		return (NULL);
	if (currentTime != ((SimCustomer *)(chair->data))->startTime)
		return (NULL);
	return (dequeueAQ(pWaitQueue));
}

void printSimCustomer(int currentTime, SimCustomer customer)
{
	(void)currentTime;
	printf("\tarrivalTime : %d\n\tserviceTime : %d\n\tstartTime : %d\n\tendTime : %d\n\n",\
		customer.arrivalTime, customer.serviceTime, customer.startTime, customer.endTime);
}

void printWaitQueueStatus(int currentTime, ArrayQueue *pWaitQueue)
{
	ArrayQueueNode	*chair;
	SimCustomer		*customer;

	chair = peekAQ(pWaitQueue);
	if (!chair)
	{
		printf("WaitQueue empty\n");
		return ;
	}
	customer = chair->data;
	printf("Next customer in line\n");
	printSimCustomer(currentTime, *customer);
}

void printReport(ArrayQueue *pWaitQueue, int serviceUserCount, int totalWaitTime)
{
	if (!isArrayQueueEmpty(pWaitQueue))
		printf("WaitQueue is not empty!!!!!!\n");
	printf("serviceUserCount : %d\n", serviceUserCount);
	printf("totalWaitTime : %d\n", totalWaitTime);
	printf("average wait time : %f\n\n", (float)totalWaitTime / serviceUserCount);
}

int main(void)
{
	ArrayQueue		*arrivalQueue;
	ArrayQueue		*waitQueue;
	ArrayQueueNode	*serviceNode;
	ArrayQueueNode	*chair;
	int				serviceUserCount;
	int				totalWaitTime;

	arrivalQueue = createArrayQueue(5);
	waitQueue = createArrayQueue(5);
	serviceUserCount = 0;
	totalWaitTime = 0;
	serviceNode = NULL;
	insertCustomer(0, 8, arrivalQueue); // 0
	insertCustomer(2, 2, arrivalQueue); // 3
	insertCustomer(4, 1, arrivalQueue); // 5
	insertCustomer(6, 1, arrivalQueue); // 6
	insertCustomer(8, 3, arrivalQueue); // 8

	for (int t = 0; t <= T_CLOSE; t++)
	{
		printf("---- time: %d ----\n", t);
		processArrival(t, arrivalQueue, waitQueue);
		chair = processServiceNodeEnd(t, serviceNode, &serviceUserCount, &totalWaitTime);
		if (chair)
		{
			free(chair);
			serviceNode = NULL;
		}
		chair = processServiceNodeStart(t, waitQueue);
		if (chair)
			serviceNode = chair;
		printWaitQueueStatus(t, waitQueue);
		if (serviceNode)
		{
			printf("Customer in process\n");
			printSimCustomer(t, *((SimCustomer *)(serviceNode->data)));
		}
		else
		{
			printf("No customer in process\n");
		}
	}
	if (serviceNode)
		free(serviceNode->data);
	free(serviceNode);
	printReport(waitQueue, serviceUserCount, totalWaitTime);
	deleteArrayQueue(&arrivalQueue);
	deleteArrayQueue(&waitQueue);
	system("leaks a.out");
}