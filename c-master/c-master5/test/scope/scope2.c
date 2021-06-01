#include <stdio.h>

int main() {
	int n = 50;
	printf("n = %d\n", n);
	// 50

	{
		// ブロックの外の既存の変数「n」
		n = 100;
		printf("n = %d\n", n);
		// 100
	}

	printf("n = %d\n", n);
	// 100

	return (0);
}