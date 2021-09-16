#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int randInt(int max, int min);

int main() {
	int n;
	scanf("%d", &n);
	n %= 13;
	printf("n %%= 13 = %d\n", n);

	return (0);
}

int randInt(int max, int min) {

	int rnd = rand() % max + min;

	return (rnd);
}