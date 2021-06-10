#include <stdio.h>
int gcd(int n, int m);

int main() {
	char buff[ 100 ];
	int a, b;

	printf("a b :");
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d %d", &a, &b);

	printf("gcd = %d\n", gcd(a, b));

	return (0);
}

int gcd(int a, int b) {
	int x = a * b;

	if (a < b) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	int r;

	r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}

	return (x / b);
}