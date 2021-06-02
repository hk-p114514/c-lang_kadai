#include <stdio.h>

int threeTimes(void);

int main() {
	int i;

	for (i = 1; i <= 10; i++) {
		printf("%2d回目: %d\n", i, threeTimes());
	}

	return (0);
}

/* threeTimes()
    概要:呼び出される度に前の呼び出しで返した値の３倍の値を返す
*/
// 引数: 無し
// 返り値  : 初回の戻り値「１」を除き、前回返した値の３倍の値を返す
int threeTimes(void) {
	static threeTimesNumber;
	static multipleValue = 1;
	/*
	multipleValueは一度しか初期化されないので、
	初回のみ1、次からは前回の呼び出しの最後で行った
	multipleValue *= 3 の結果が返される。
	*/
	threeTimesNumber = multipleValue;
	multipleValue *= 3;
	return (threeTimesNumber);
}
