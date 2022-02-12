#include <stdio.h>

int main() {
	unsigned int n;
	printf("数値を入力して下さい: ");
	scanf("%d", &n);

	// 入力された数値を符号なし整数として表示する
	printf("%u\n", n);

	return (0);
}