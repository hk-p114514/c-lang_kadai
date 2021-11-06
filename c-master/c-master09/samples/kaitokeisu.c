#include <math.h>
#include <stdio.h>

int main() {
	float a, b, c, d, x1, x2;

	a = 1.0;
	b = 96325.0;
	c = 0.74125;

	d = sqrt(b * b - 4 * a * c);

	x2 = (-b - d) / (2 * a);

	x1 = c / (a * x2);

	printf("x1 = %g, x2 = %g\n", x1, x2);

	return (0);
}
