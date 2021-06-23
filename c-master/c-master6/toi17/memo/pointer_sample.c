#include <stdio.h>

void foo(int *x);

int main() {
	int x = 10;

	printf("main:  x = %d, &x = %p\n&x + 1 = %p\n\n", x, &x, &x + 1);
	foo(&x);
	printf("main:  x = %d, &x = %p\n", x, &x);

	int a[ 10 ] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
	printf("5[a] = %d\n", 5 [ a ]);
	/*========================================
	  array[n]は、*(array + n)のシンタックスシュガー
	========================================*/

	return (0);
}

void foo(int *x) {
	/*========================================
	  int *x; という宣言は、

	int* x;
	int * x;
	int *x;
	のどれでも同じ意味になる。
  ー＞c言語のスペースは意味を持たない
	========================================*/
	printf("foo : *x = %d,  x = %p\n", *x, x);
	*x = 50;
	printf("foo : *x = %d,  x = %p\n", *x, x);

	return;
}
