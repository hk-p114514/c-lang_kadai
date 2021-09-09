#include "stack.h"
#include <stdio.h>

// 機能：スタックを初期化し、空の状態にする
// 引数：[s : 初期化するスタック]
void initStack(Stack *s) {
	s->sp = 0;
	return;
}

// 機能：スタックにデータを格納する
// 引数：[s : データの格納対象となるスタック] [data : スタックsへ格納するデータ]
// 戻り値：正常終了：1、スタック・オーバーフロー：0
int push(Stack *s, int data) {
	s->sp++;
	if (s->sp >= STACK_SIZE) {
		return (0);
	} else {
		s->storage[ s->sp ] = data;
		return (1);
	}
}

// 機能：スタックからデータを取り出す
// 引数：[s : データの取り出し対象となるスタック] [data : スタックsから取り出したデータ]
// 戻り値：正常終了：1、スタック・アンダーフロー・0
int pop(Stack *s, int *data) {
	if (s->sp <= 0) {
		return (0);
	} else {
		s->sp--;
		*data = s->storage[ s->sp ];
		return (1);
	}
}