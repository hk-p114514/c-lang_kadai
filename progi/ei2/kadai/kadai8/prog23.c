#include "stack.h"
#include <stdio.h>

int main() {
	Stack s;

	initStack(&s);

	// 入力処理
	int state = 1, n;
	while () {
		printf("n\t:%d\n", n);
		printf("state\t:%d\n", state);
		state = push(&s, n);
	}

	return (0);
}