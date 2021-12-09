#include <stdio.h>
#include <stdlib.h>

long long fib(int n);
long long fib_tail(long long a, long long b, int n);

int main(int argc, char *argv[]) {
	int n;

	if (argc < 2) {
		fprintf(stderr, "引数に正数を指定してください。\n");
		exit(1);
	}
	sscanf(argv[ 1 ], "%d", &n);

	printf("%d\n", fib(n));

	return (0);
}

// フィボナッチ数列の第n項の値を返す
long long fib(int n) {
	return (fib_tail(2, 1, n));
}

long long fib_tail(long long a, long long b, int n) {
	// a: 第n-1項の値
	// b: 第n-2項の値
	// n: 調べる項
	if (n <= 2) {
		return (b);
	} else if (n <= 3) {
		return (a);
	} else {
		// 次の第n-1項の値はa+b
		// 次の第n-2項の値はb+(a-b) -->(a-b)は第n-3項の値なので、b+(a-b)は次の第n-2項の値になる
		// nは1ずつ減らす
		return (fib_tail(a + b, b + (a - b), n - 1));
	}
}
