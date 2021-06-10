#include <stdio.h>

typedef struct {
	int numerator;   // 分子
	int denominator; // 分母
} Fraction;

Fraction getFraction(void);
Fraction frcCreate(int numerator, int denominator);
Fraction frcMul(Fraction x, Fraction y);
Fraction frcAdd(Fraction x, Fraction y);
Fraction frcSub(Fraction x, Fraction y);
Fraction frcDivision(Fraction x, Fraction y);
Fraction irreducible(Fraction x);
void frcPrint(Fraction x);
int frcGetNumerator(Fraction x);
int frcGetDenominator(Fraction x);

int main() {
	Fraction a, b;

	// 二つの分数を入力する
	a = getFraction(); // 分数aをキーボードより入力する
	b = getFraction(); // 分数aをキーボードより入力する

	// 分数を四則演算する

	return (0);
}

/*================================================================================*/

/*
    getFraction()
    概要：キーボードから、分数を n / d の形式で入力する
*/
// 引数：なし
// 返り値 ： 入力された n / d 形式の分数を表すFraction型のデータ
Fraction getFraction(void) {
	char buff[ 256 ];
	Fraction input;
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d/%d", &input.numerator, &input.denominator);

	return (input);
}

/*
    frcPrint()
    概要：渡されたFraction型のデータを n / d の形式で出力する
*/
// 第一引数：表示したいFraction型のデータ
void frcPrint(Fraction data) {
	printf("%d/%d\n", frcGetNumerator(data), frcGetDenominator(data));

	return;
}

/*
    frcCreate()
    概要：分子の値numeratorと分母の値denominatorから作られる分数を返す
*/
// 第一引数：分子の値
// 第二引数：分母の値
// 返り値：引数から作られた分数(Fraction型)
Fraction frcCreate(int numerator, int denominator) {
	Fraction created;
	created.numerator = numerator;
	created.denominator = denominator;

	return (created);
}

/*
    frcAdd()
    概要：与えられた２つの分数xとyの加算結果(x + y)を返す
*/
// 第一引数：加算したい１つ目の分数
// 第二引数：加算したい２つ目の分数
/* 第一引数と第二引数の順番は関係ない */
// 返り値：引数に渡された分数の加算結果の分数(Fraction型)
Fraction frcAdd(Fraction x, Fraction y) {
	Fraction added;

	added.numerator = frcGetNumerator(x) + frcGetNumerator(y);
	added.denominator = frcGetDenominator(x) + frcGetDenominator(y);

	return (added);
}

/*
    frcSub()
    概要：与えられた２つの分数xとyの減算結果を返す
*/
// 第一引数：減算したい１つ目の分数
// 第二引数：減算したい２つ目の分数
/* 第一引数と第二引数の順番は関係ない */
// 返り値：引数に渡された分数の減算結果の分数(Fraction型)
Fraction frcSub(Fraction x, Fraction y) {
	Fraction substracted;

	substracted.numerator = frcGetNumerator(x) - frcGetNumerator(y);
	substracted.denominator = frcGetDenominator(x) - frcGetDenominator(y);

	return (substracted);
}

/*
    frcMul()
    概要：与えられた２つの分数xとyの乗算結果(x * y)を返す
*/
// 第一引数：乗算したい１つ目の分数
// 第二引数：乗算したい２つ目の分数
/* 第一引数と第二引数の順番は関係ない */
// 返り値：引数に渡された分数の乗算結果の分数(Fraction型)
Fraction frcMul(Fraction x, Fraction y) {
	Fraction multiplied;

	multiplied.numerator = frcGetNumerator(x) * frcGetNumerator(y);
	multiplied.denominator = frcGetDenominator(x) * frcGetDenominator(y);

	return (multiplied);
}

/*
    frcDivision()
    概要：与えられた２つの分数xとyの割り算結果を返す
*/
// 第一引数：割り算したい１つ目の分数
// 第二引数：割り算したい２つ目の分数
/* 第一引数と第二引数の順番は関係ない */
// 返り値：引数に渡された分数の割り算結果の分数(Fraction型)
Fraction frcDivision(Fraction x, Fraction y) {
	Fraction isDivision;

	isDivision.numerator = frcGetNumerator(x) - frcGetNumerator(y);
	isDivision.denominator = frcGetDenominator(x) - frcGetDenominator(y);

	return (isDivision);
}

/* frcGetNumerator()
    概要:分数xの分子の値を返す
*/
// 第一引数: Fraction型の変数x
// 返り値  : Fraction型の変数xの分子の値
int frcGetNumerator(Fraction x) {
	return (x.numerator);
}

/* frcGetDenominator()
    概要:分数xの分母の値を返す
*/
// 第一引数: Fraction型の変数x
// 返り値  : Fraction型の変数xの分母の値
int frcGetDenominator(Fraction x) {
	return (x.denominator);
}

/* Fraction irreducible();
	概要:渡された分数を既約分数にして返す
*/
// 第一引数: Fraction型の分数の値
// 返り値  : 既約分数にした分数の値
Fraction irreducible(Fraction x) {

}