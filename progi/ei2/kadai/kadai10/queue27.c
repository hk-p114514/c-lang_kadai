#include "queue27.h"
#include <stdio.h>

// Function: initQueue
// Description: Initializes the queue
// Arguments: q - pointer to the queue
// Returns: void
void initQueue(Queue *q) {
	*q->head = getEmptyList();
	return;
}

// Function: enQueue
// Description: Adds an element to the queue
// Arguments: q - pointer to the queue
//            data - the data to be added
// Returns: when successful, returns (1), fails otherwise (0)
int enQueue(Queue *q, int data) {
	return (insertHead(q->head, data));
}

// Function: deQueue
// Description: Removes an element from the queue
// Arguments: q - pointer to the queue
//         data - pointer to the data to be removed
// Returns: when successful - (1) , fails otherwise - (0)
int deQueue(Queue *q, int *data) {
	Cell **before = getNextCellHead(*q->head);
	while (isEmptyList(*before) == 0 && isEmptyList(getNextCell(*q->head)) == 0) {
		before = q->head;
		q->head = getNextCellHead(*q->head);
	}
	if (isEmptyList(*before) == 0) {
		return (0);
	}
	*data = getCellData(*before);
	removeHead(before);
	return (1);
}

// Function: freeQueue
// Description: Frees the queue
// Arguments: q - pointer to the queue
// Returns: void
void freeQueue(Queue *q) {
	removeList(q->head);
}
