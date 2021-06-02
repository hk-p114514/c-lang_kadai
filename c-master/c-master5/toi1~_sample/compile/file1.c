#include <stdio.h>

int x;
int z;

int func1(void);
void func2(void);

int main() {
	z = func1();
	func2();
	printf("x = %d, z = %d\n", x, z);
}
