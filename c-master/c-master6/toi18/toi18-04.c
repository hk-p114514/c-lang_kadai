#include <stdio.h>

int main() {
	int source[ 10 ] = {1, 5, 8, 12, 2, 6, -6, 0, 4, 10};
	int twice[ 10 ];
	int i;

	for (i = 0; i < 10; i++) {
		*(twice + i) = *(source + i) * 2;
	}
	for (i = 0; i < 10; i++) {
		printf("source[%d] = %d, twice[%d] = %d\n", i, *(source + i), i, *(twice + i));
	}

	return (0);
}
