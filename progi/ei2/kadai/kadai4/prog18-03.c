#include <stdio.h>

typedef struct {
	int numerator;   // 分子
	int denominator; // 分母
} Fraction;

Fraction getFraction(void);
Fraction frcCreate(int numerator, int denominator);
Fraction frcMul(Fraction x, Fraction y);
void frcPrint(Fraction x);

int main() {
	Fraction a, b, c;

	a = getFraction(); // 分数aをキーボードより入力する

	printf("a = ");
	frcPrint(a); // 入力した分数aを表示
	putchar('\n');

	b = frcCreate(2, 3); // 分数bは2/3

	// printf("b = ");
	// frcPrint(b); // 分数bを表示
	// putchar('\n');

	// c = frcMul(a, b); // c = a * b

	// printf("a * b = ");
	// frcPrint(c); // 乗算結果である分数cの表示
	// putchar('\n');

	return (0);
}

/*
    getFractoin()
    概要：キーボードから、分数を n / d の形式で入力する
*/
// 引数：なし
// 返り値 ： 入力された n / d 形式の分数を表すFraction型のデータ
Fraction getFraction(void) {
	char buff[ 256 ];
	Fraction input;
	int numerator, denominator;
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d/%d", &numerator, &denominator);

	input.numerator = numerator;
	input.denominator = denominator;

	return (input);
}

/*
    frcPrint()
    概要：渡されたFraction型のデータを n / d の形式で出力する
*/
// 第一引数：表示したいFraction型のデータ
void frcPrint(Fraction data) {
	printf("%d/%d\n", data.numerator, data.denominator);

	return;
}

/*
    frcCreate()
    概要：
*/