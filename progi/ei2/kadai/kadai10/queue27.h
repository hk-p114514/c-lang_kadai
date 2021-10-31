#include "list.h"

// Creating a Queue using a list structure
typedef struct {
	List **head; // Pointer to the head of the list
	List **tail; // Pointer to the tail of the list
} Queue;

void initQueue(Queue *q);
int enQueue(Queue *q, int data);
int deQueue(Queue *q, int *data);
void freeQueue(Queue *q);
