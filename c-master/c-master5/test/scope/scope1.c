#include <stdio.h>

int main() {
	int n = 50;
	printf("n = %d\n", n);
	// 50

	{
		// ブロック内における新たな変数「n」
		int n = 100;
		printf("n = %d\n", n);
		// 100
	}

	printf("n = %d\n", n);
	// 50

	return (0);
}