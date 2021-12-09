#include <stdio.h>
#include <stdlib.h>

int sankaku(int n, int s);

int main(int argc, char *argv[]) {
	int n;

	if (argc < 2) {
		fprintf(stderr, "引数に正数nを指定してください。\n");
		exit(1);
	}
	sscanf(argv[ 1 ], "%d", &n);

	printf("%d\n", sankaku(n, 1));

	return (0);
}

// s は第n項の三角数
int sankaku(int n, int s) {
	// s = 第n-1項の三角数
	if (n <= 1) {
		// 第1項の場合は 1
		return (s);
	} else {
		// 第n項の答えは、第n-1項の答えとnの和
		return (sankaku(n - 1, s + n));
	}
}
