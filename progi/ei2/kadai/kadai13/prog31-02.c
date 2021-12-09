#include <stdio.h>
#include <stdlib.h>

double ipow(double a, int x, double ans);

int main(int argc, char *argv[]) {
	double a;
	int x;

	if (argc < 3) {
		fprintf(stderr, "第1引数に実数を、第2引数に整数を指定してください。\n");
		exit(1);
	}
	sscanf(argv[ 1 ], "%lf", &a);
	sscanf(argv[ 2 ], "%d", &x);

	printf("%g\n", ipow(a, x, 1.0));

	return (0);
}

// ans は a^x を計算した値
double ipow(double a, int x, double ans) {
	if (x > 0) {
		// x > 0のときはa^x = a * a * ...
		return (ipow(a, x - 1, a * ans));
	} else if (x < 0) {
		// x < 0のときはa^x = (1/a) * (1/a) * ...
		return (ipow(a, x + 1, ans / a));
	} else if (x == 0) {
		// x = 0のときは1
		return (ans);
	}
}
