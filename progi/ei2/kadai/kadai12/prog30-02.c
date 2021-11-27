//
//  分割数（整数ｎを正の数の和で表す）
//
#include <stdio.h>
#include <stdlib.h>

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

// nをa以下の数の和で、メモ化再帰で求める
int partitionNumberRec(int n, int a) {
	/*
	基底条件:
	a = 1 (1以下の自然数の和で表す = 全て1)のとき = それ以上分割できないとき= 1
	n < 0 or a <= 0 (範囲外)のとき、0
	*/
	static int memo[ 100 ][ 100 ] = {};

	if (a == 1) {
		// a = 1のとき、1以下の自然数の和で表す
		// つまり、「全て1で表す」の１通りしか存在しない
		memo[ n ][ a ] = 1;
		return (1);
	} else if (n < 0 || a <= 0) {
		// nそのものがマイナス、またはaがマイナス、またはaが0のとき、
		// そもそも分割できないので、0
		memo[ n ][ a ] = 0;
		return (0);
	} else if (memo[ n ][ a ] == 0) {
		/*
		p(n,a)をnを自然数aで始まるように分割するときの分割数とすると、
		p(n,a) = p(n-a,a) + p(n,a-1)といえる。
		*/
		memo[ n ][ a ] = partitionNumberRec(n - 1, a) + partitionNumberRec(n - 1, a - 1);
	} else {
		// すでに計算済みの値を使う
		return (memo[ n ][ a ]);
	}
}
