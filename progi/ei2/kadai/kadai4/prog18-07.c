#include <stdio.h>

typedef struct {
	int bunsi; // 分子
	int bunbo; // 分母
} Fraction;

Fraction getFraction(void);
Fraction frcCreate(int bunsi, int bunbo);
Fraction frcMul(Fraction x, Fraction y);
void frcPrint(Fraction x);

int main() {
	Fraction a, b, c;

	a = getFraction(); // 分数aをキーボードより入力する

	printf("a = ");
	frcPrint(a); // 入力した分数aを表示
	putchar('\n');

	b = frcCreate(2, 3); // 分数bは2/3

	printf("b = ");
	frcPrint(b); // 分数bを表示
	putchar('\n');

	c = frcMul(a, b); // c = a * b

	printf("a * b = ");
	frcPrint(c); // 乗算結果である分数cの表示
	putchar('\n');

	return (0);
}

/*
    getFraction()
    概要：キーボードから、分数を n / d の形式で入力する
*/
// 引数：なし
// 返り値 ： 入力された n / d 形式の分数を表すFraction型のデータ
Fraction getFraction(void) {
	char buff[ 256 ];
	Fraction input;
	int bunsi, bunbo;
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d/%d", &bunsi, &bunbo);

	input.bunsi = bunsi;
	input.bunbo = bunbo;

	return (input);
}

/*
    frcPrint()
    概要：渡されたFraction型のデータを n / d の形式で出力する
*/
// 第一引数：表示したいFraction型のデータ
void frcPrint(Fraction data) {
	printf("%d/%d\n", data.bunsi, data.bunbo);

	return;
}

/*
    frcCreate()
    概要：分子の値bunsiと分母の値bunboから作られる分数を返す
*/
// 第一引数：分子の値
// 第二引数：分母の値
// 返り値：引数から作られた分数(Fraction型)
Fraction frcCreate(int bunsi, int bunbo) {
	Fraction created;
	created.bunsi = bunsi;
	created.bunbo = bunbo;

	return (created);
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

	multiplied.bunsi = x.bunsi * y.bunsi;
	multiplied.bunbo = x.bunbo * y.bunbo;

	return (multiplied);
}
