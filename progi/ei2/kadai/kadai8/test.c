#include "stack.h"
#include <stdio.h>

int main() {
	Stack stack;
	initStack(&stack);

	putchar('\n');

	int data, state;
	do {
		printf("push data : ");
		scanf("%d", &data);
		state = push(&stack, data);
	} while (state == 1);

	state = push(&stack, 999);

	putchar('\n');

	state = pop(&stack, &data);

	while (state == 1) {
		printf("pop data : %d\n", data);
		state = pop(&stack, &data);
	}

	return 0;
}
