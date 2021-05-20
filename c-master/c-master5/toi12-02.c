#include <stdio.h>

void ast(int n);

int main() {
	char buff[ 1024 ];
	int n;
	printf("Input n : ");
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d", &n);
	ast(n);

	return (0);
}

/*
    ast()
    概要：引数nの数だけアスタリスク(*)を横一列に表示する
*/
// 第一引数：アスタリスク（＊）を表示する個数
// 返り値：なし
void ast(int n) {
	for (int i = 0; i < n; i++) {
		putchar('*');
	}
	putchar('\n');

	return;
}