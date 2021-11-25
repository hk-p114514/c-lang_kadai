#include <stdio.h>
#include <stdlib.h>

long long cntHanoi(long long n);

int main(int argc, char *argv[]) {
	long long n;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <number of disk>\n", argv[ 0 ]);
		exit(1);
	}
	sscanf(argv[ 1 ], "%d", &n);

	printf("%d枚を移動する手順: %lld回\n", n, cntHanoi(n));

	return (0);
}

long long cntHanoi(long long n) {
	if (n > 0) {
		return (2 * cntHanoi(n - 1) + 1);
	} else {
		return (0);
	}
}
