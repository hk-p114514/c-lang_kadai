#include "queue.h"
#include "stack.h"
#include <stdio.h>

/*
規則1 : 文字列は入力された順に連結する。但し、先頭の+,-は連結の際削除する
規則2 : 先頭が+で始まる文字列はそのまま、-で始まる文字列は文字列を逆順にして連結する
規則3 : 先頭が+,-以外で始まる文字列は無視する。
*/
int main() {
	int n;
	char buff[ 256 ];

	// 文字列の個数を入力
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d", &n);

	return (0);
}