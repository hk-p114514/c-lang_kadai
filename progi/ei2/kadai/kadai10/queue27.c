#include "queue27.h"
#include <stdio.h>

// Function: initQueue
// Description: Initializes the queue
// Arguments: q - pointer to the queue
// Returns: void
void initQueue(Queue *q) {
	*q->head = getEmptyList();
	*q->tail = getEmptyList();
	return;
}

// Function: enQueue
// Description: Adds an element to the queue
// Arguments: q - pointer to the queue
//            data - the data to be added
// Returns: when successful, returns (1), fails otherwise (0)
int enQueue(Queue *q, int data) {
	if (insertHead(q->head, data) == 0) {
		return 0;
	}
}

// Function: deQueue
// Description: Removes an element from the queue
// Arguments: q - pointer to the queue
//         data - pointer to the data to be removed
// Returns: when successful - (1) , fails otherwise - (0)
int deQueue(Queue *q, int *data) {
	if (isEmptyList(*q->head) == 1) {
		return (0);
	}

	while (isEmptyList(getNextCell(*q->head)) == 0) {
		q->head = getNextCellHead(*q->head);
	}
	*data = getCellData(*q->head);

	return (removeTail(q->head));
}

// Function: freeQueue
// Description: Frees the queue
// Arguments: q - pointer to the queue
// Returns: void
void freeQueue(Queue *q) {
	removeList(q->head);
}
