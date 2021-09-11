#include "stack.h"
#include <stdio.h>

int main() {
	Stack s;

	initStack(&s);

	int train;
	while (scanf("%d", &train) != EOF) {
		// printf("sp : %d\n", s.sp);
		if (train == 0) {
			// 行き止まりから発車された電車を出力する
			int leave;
			pop(&s, &leave);
			printf("pop %d\n", leave);
		} else {
			// 行き止まりに電車を詰める
			push(&s, train);
			// printf("push %d\n", train);
		}
	}

	return (0);
}