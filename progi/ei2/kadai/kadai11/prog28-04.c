#include <stdio.h>
#include <stdlib.h>

long long fib(int n);

int main(int argc, char *argv[]) {
	int n;

	if (argc < 2) {
		fprintf(stderr, "引数に正数を指定してください。\n");
		exit(1);
	}
	sscanf(argv[ 1 ], "%d", &n);

	printf("%lld\n", fib(n));

	return (0);
}

long long fib(int n) {
	// 基底条件：n = 1 , 2のとき1
	if (n <= 2) {
		return (1);
	} else {
		return (fib(n - 1) + fib(n - 2));
	}
}
