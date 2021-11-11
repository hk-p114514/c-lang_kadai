#include <stdio.h>
#include <stdlib.h>

void printBinaryN(int d, int n);

int main(int argc, char *argv[]) {
	int d, n;

	if (argc < 3) {
		fprintf(stderr, "10進整数と表示するビット長を引数に指定してください。\n");
		exit(1);
	}
	sscanf(argv[ 1 ], "%d", &d);
	sscanf(argv[ 2 ], "%d", &n);

	printBinaryN(d, n);
	putchar('\n');

	return (0);
}

void printBinaryN(int d, int n) {
	if (d < 2) {
		// 0を打つかどうか
		// 1桁は自分自身を出力するのでn - 1個の0を出す
		for (int i = 0; i < n - 1; i++) {
			putchar('0');
		}
		printf("%d", d);
	} else {
		printBinaryN(d / 2, n - 1);
		printf("%d", d % 2);
	}
}
