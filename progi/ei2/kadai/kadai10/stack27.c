#include "stack27.h"
#include <stdio.h>

// スタックの初期化
// 引数: 操作対象のスタックを指すポインタ
// 戻り値: なし
void initStack(Stack *s) {
	*s->head = getEmptyList();
	return;
}

// スタックにデータを追加
// 引数: 操作対象のスタックを指すポインタ、追加するデータ
// 戻り値: 追加に成功した場合は1、追加に失敗した場合は0
int push(Stack *s, int data) {
	return (insertHead(s->head, data));
}

// スタックからデータを取り出す
// 引数: 操作対象のスタックを指すポインタ、取り出したデータを格納する変数へのポインタ
// 戻り地: 取り出しに成功した場合は1、取り出しに失敗した場合は0
// Summary: Extracting data from the stack
// Arguments: A pointer to the stack, a pointer to the variable to store the extracted
// data Return: 1 if the extraction is successful, 0 if the extraction is failed
int pop(Stack *s, int *data) {
	if (isEmptyList(*s->head)) {
		return 0;
	}
	*data = getCellData(*s->head);
	removeHead(s->head);
	return (1);
}

// スタックを解放する
// 引数: 操作対象のスタックを指すポインタ
// 戻り値: なし
void freeStack(Stack *s) {
	removeList(s->head);
	return;
}
