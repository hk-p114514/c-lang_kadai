#include "list.h"
// make type stack use the type List

typedef struct {
	List **head;
} Stack;

void initStack(Stack *stack);
int push(Stack *stack, int data);
int pop(Stack *stack, int *data);
void freeStack(Stack *stack);