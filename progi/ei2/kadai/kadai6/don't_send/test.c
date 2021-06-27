#include <stdio.h>

int main() {
	double a, b, c, d;
	scanf("%lf %lf", &a, &b);
	scanf("%lf %lf", &c, &d);

	printf("(bc - ad)j / c^2 + d^2 = %lf\n", (b * c - a * d) / (c * c + d * d));

	return (0);
}