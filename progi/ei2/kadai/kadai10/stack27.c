#include "stack27.h"
#include <stdio.h>

void initStack(Stack *stack);
int push(Stack *stack, int data);
int pop(Stack *stack, int *data);
void freeStack(Stack *stack);

// スタックの初期化
// 引数: 操作対象のスタックを指すポインタ
// 戻り値: なし
void initStack(Stack *stack) {
	*stack->head = getEmptyList();
	return;
}

// スタックにデータを追加
// 引数: 操作対象のスタックを指すポインタ、追加するデータ
// 戻り値: 追加に成功した場合は1、追加に失敗した場合は0
int push(Stack *stack, int data) {
	return (insertHead(stack->head, data));
}

// スタックからデータを取り出す
// 引数: 操作対象のスタックを指すポインタ、取り出したデータを格納する変数へのポインタ
// 戻り地: 取り出しに成功した場合は1、取り出しに失敗した場合は0
int pop(Stack *stack, int *data) {
	*data = getCellData(*stack->head);
	return (removeHead(stack->head));
}

// スタックを解放する
// 引数: 操作対象のスタックを指すポインタ
// 戻り値: なし
void freeStack(Stack *stack) {
	removeList(stack->head);
	return;
}
