#include "fraction.h"
#include <stdio.h>

void frcPrintOperation(char op, Fraction x, Fraction y);

int main() {
	Fraction a, b, c;
	char op[] = "+-*/";

	b = frcCreate(4, 3);
	a = frcCreate(5, 2);
	c = frcCreate(7, 8);

	// a^2 - b / c を計算する
	Fraction calc;
	calc = frcDiv(frcSub(frcMul(a, a), b), c);

	frcPrint(calc);
	putchar('\n');

	return (0);
}

/*========================================*/
// 分数xと分数yに、2項演算(x op y)を実行した結果を表示する
//   [引　数] op   : 2項演算子（+, -, *, /)
//            x, y : 演算対象となる分数
//   [表示例] 1/2 + 1/4 = 3/4
void frcPrintOperation(char op, Fraction x, Fraction y) {
	Fraction a;

	switch (op) {
	case '+':
		a = frcAdd(x, y);
		break;
	case '-':
		a = frcSub(x, y);
		break;
	case '*':
		a = frcMul(x, y);
		break;
	case '/':
		a = frcDiv(x, y);
		break;
	default:
		printf("%c: 演算子が不正です。\n", op);
		return;
	}
	a = frcReduction(a);
	frcPrint(x);
	printf(" %c ", op);
	frcPrint(y);
	printf(" = ");
	frcPrint(a);
	putchar('\n');

	return;
}
