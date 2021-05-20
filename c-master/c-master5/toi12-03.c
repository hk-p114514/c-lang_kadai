#include <stdio.h>

void ast(int n);
void rectangle(int n, int m);

int main() {
	char buff[ 1024 ];
	int n, m;
	printf("n m : ");
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d %d", &n, &m);

	rectangle(n, m);
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

/*
    rectangle()
    概要：n個のアスタリスク（＊）をm行に渡って表示する
*/
// 第一引数：アスタリスク（＊）を表示する個数
// 第二引数：アスタリスク（＊）を表示する行数
// 返り値：なし
void rectangle(int n, int m) {
	for (int i = 0; i < m; i++) {
		ast(n);
	}

	return;
}