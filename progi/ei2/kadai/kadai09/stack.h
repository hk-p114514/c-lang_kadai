#define STACK_SIZE (30)

typedef struct {
	int storage[ STACK_SIZE ];
	int sp;
} Stack;

void initStack(Stack *s);

int push(Stack *s, int data);

int pop(Stack *s, int *data);