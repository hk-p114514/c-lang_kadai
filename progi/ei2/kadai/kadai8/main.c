#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int randInt(int max);

int main() {
	for (int i = 0; i < 100; i++) {
		printf("rnd : %d\n", randInt(10));
	}
}

int randInt(int max) {
	int rnd = rand() % (max + 1);

	return (rnd);
}