#include "list.h"

/*
 * スタックのストレージ部分にリストを使用すると、
 * スタックポインタが不要になるので、
 *　リスト型そのものをスタックとして扱うことができる。
 */
typedef List *Stack;

void initStack(Stack *stack);
int push(Stack *stack, int data);
int pop(Stack *stack, int *data);
void freeStack(Stack *stack);