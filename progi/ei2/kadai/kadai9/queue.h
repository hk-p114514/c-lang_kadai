#define QUEUE_SIZE (1100)

typedef struct {
	int storage[ QUEUE_SIZE ];
	int head;
	int tail;
} Queue;

void initQueue(Queue *q);
int enQueue(Queue *q, int data);
int deQueue(Queue *q, int *data);
