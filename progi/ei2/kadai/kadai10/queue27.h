#include "list.h"

typedef struct {
	List **head;
} Queue;

void initQueue(Queue *q);
int enQueue(Queue *q, int data);
int deQueue(Queue *q, int *data);
void freeQueue(Queue *q);
