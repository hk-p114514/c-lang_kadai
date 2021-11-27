#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE (100)

int partitionNumber(int n);
int partitionNumberRec(int n, int a);

int main(int argc, char *argv[]) {
	int n;

	if (argc < 2) {
		fprintf(stderr, "整数を引数に指定してください。\n");
		exit(1);
	}
	sscanf(argv[ 1 ], "%d", &n);

	printf("%d\n", partitionNumber(n));

	return (0);
}

int partitionNumber(int n) {
	return (partitionNumberRec(n, n)); // nをn以下の数の和で表す
}

// nをa以下の数の和でメモ化再帰で表す
int partitionNumberRec(int n, int a) {
	/*
	基底条件:
	a = 1 (1以下の自然数の和で表す = 全て1)のとき = それ以上分割できないとき= 1
	n < 0 or a <= 0 (範囲外)のとき、0
	*/
	static int memo[ ARR_SIZE ][ ARR_SIZE ] = {};
	static int isRecorded[ ARR_SIZE ][ ARR_SIZE ] = {};

	if (a == 1) {
		/*
		a = 1のとき、分割の方法は1つしかない
		*/
		memo[ n ][ a ] = 1;
		isRecorded[ n ][ a ] = 1;
		return (1);
	} else if (n < 0 || a <= 0) {
		// nそのものが範囲外、もしくはaが0以下のとき、
		// 分割できないということなので、0を返す
		isRecorded[ n ][ a ] = 1;
		return (0);
	} else if (isRecorded[ n ][ a ] == 0) {
		// ここまで来たとき、まだメモ化されていない
		// ここでメモ化する
		memo[ n ][ a ] = partitionNumberRec(n - a, a) + partitionNumberRec(n, a - 1);
		isRecorded[ n ][ a ] = 1;
	}

	return (memo[ n ][ a ]);
}
