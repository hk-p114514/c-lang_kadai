#include "list.h"

typedef List *Stack;

void initStack(Stack *stack);
int push(Stack *stack, int data);
int pop(Stack *stack, int *data);
void freeStack(Stack *stack);