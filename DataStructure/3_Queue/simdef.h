#ifndef _SIMDEF_H_
#define _SIMDEF_H_

#include "arrayqueue.h"

// typedef enum SimStatusType { ARRIVAL, START, END } SimStatus;

typedef struct SimCustomerType
{
	int arrivalTime;
	int serviceTime;
	int startTime;
	int endTime;
} SimCustomer;

void insertCustomer(int arrivalTime, int processTime, ArrayQueue *pQueue);
void processArrival(int currentTime, ArrayQueue *pArrivalQueue, ArrayQueue *pWaitQueue);
ArrayQueueNode* processServiceNodeStart(int currentTime, ArrayQueue *pWaitQueue);
ArrayQueueNode* processServiceNodeEnd(int currentTime, ArrayQueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime);
void printSimCustomer(int currentTime, SimCustomer customer);
void printWaitQueueStatus(int currentTime, ArrayQueue *pWaitQueue);
void printReport(ArrayQueue *pWaitQueue, int serviceUserCount, int totalWaitTime);

#endif