#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int randInt(int max, int min);

int main() {
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		printf("%d\n", randInt(10, 1));
	}

	printf("/*========================================*/\n");

	for (int i = 0; i < 10; i++) {
		printf("%d\n", randInt(10, 1));
	}

	return (0);
}

int randInt(int max, int min) {

	int rnd = rand() % max + min;

	return (rnd);
}