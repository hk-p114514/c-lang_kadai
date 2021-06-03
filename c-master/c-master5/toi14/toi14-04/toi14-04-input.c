#include <stdio.h>

int data[ 1000 ]; // n個のデータを格納する大域変数

/* input()
    概要:n個の値を大域変数data[]に格納する
*/
// 第一引数: 無し
// 返り値  : 入力したデータ数n
int input(void) {
	char buff[ 1024 ];
	int n;

	// nの入力
	printf("Input n :");
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d", &n);

	// n個のデータの入力
	for (int i = 0; i < n; i++) {
		printf("Input data[%d] :", i);
		fgets(buff, sizeof(buff), stdin);
		sscanf(buff, "%d", &data[ i ]);
	}

	return (n);
}
