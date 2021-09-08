#include "stack.h"
#include <stdio.h>

void initStack(Stack *s) {
	s->sp = 0;
	return;
}

int push(Stack *s, int data) {
	if (s->sp > STACK_SIZE) {
		return (0);
	} else {
		s->storage[ s->sp ] = data;
		s->sp++;
		return (1);
	}
}

int pop(Stack *s, int *data) {
	if (s->sp == 0) {
		return (0);
	} else {
		s->sp--;
		data = s->storage[ s->sp ];
		return (1);
	}
}