#include "fraction.h"
#include <stdio.h>
#include <stdlib.h> // abs()関数を使用するために必要

// 名前変えました
int getGcm(int m, int n);
int getLcm(int m, int n);

/*========================================*/
// Fraction型で表される分数の分子の値を返す
// [引　数] Fraction型で表現される分数
// [戻り値] 分子の値
int frcGetNumerator(Fraction x) {
	return (x.numerator);
}

/*========================================*/
// Fraction型で表される分数の分母の値を返す
// [引　数] Fraction型で表現される分数
// [戻り値] 分母の値
int frcGetDenominator(Fraction x) {
	return (x.denominator);
}

/*========================================*/
// キーボードより、a/bの形で分数を入力する
//   [引　数] なし
//   [戻り値] Fraction型で表現される分数
Fraction getFraction(void) {
	char buff[ 256 ];
	Fraction input;
	int numerator, denominator;
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d/%d", &numerator, &denominator);
	input = frcCreate(numerator, denominator);

	return (input);
}

/*========================================*/
// 分子と分母の値からFraction型で表される分数を返す
//   [引　数] numerator   : 分子の値
//            denominator : 分母の値
//   [戻り値] Fraction型で表現される分数
Fraction frcCreate(int numerator, int denominator) {

	Fraction created;
	created.numerator = numerator;
	created.denominator = denominator;

	return (created);
}

/*========================================*/
// 分数xとyの加算結果を返す
//   [引　数] x, y : 加算対象となる分数
//   [戻り値] x + y を計算して得られる分数
Fraction frcAdd(Fraction x, Fraction y) {
	// 各分数の分母、分子の値を読み込む
	int numeratorX = frcGetNumerator(x);
	int denominatorX = frcGetDenominator(x);

	int numeratorY = frcGetNumerator(y);
	int denominatorY = frcGetDenominator(y);

	// 二つの分母の値の最小公倍数を求める
	int lcm = getLcm(denominatorX, denominatorY);
	// 各分母がどれくらい変化したかを求める
	int changeX = lcm / denominatorX;
	int changeY = lcm / denominatorY;
	// 分子の値を分母に合わせる
	numeratorX *= changeX;
	numeratorY *= changeY;
	// 加算結果の分数の分母を求めた最小公倍数にする
	int denominator = lcm;
	int numerator = numeratorX + numeratorY;

	Fraction added = frcCreate(numerator, denominator);

	return (added);
}

/*========================================*/
// 分数xとyの減算結果を返す
//   [引　数] x, y : 減算対象となる分数
//   [戻り値] x - y を計算して得られる分数
Fraction frcSub(Fraction x, Fraction y) {
	Fraction substracted;
	// 引き算は足し算の逆（符号が）なので、frcAddが使える

	// 引く方の分子をマイナスにしてfrcAddにわたす。
	int numeratorY = frcGetNumerator(y);
	int denominatorY = frcGetDenominator(y);

	substracted = frcAdd(x, frcCreate(-numeratorY, denominatorY));

	return (substracted);
}

/*========================================*/
// 分数xとyの乗算結果を返す
//   [引　数] x, y : 乗算対象となる分数
//   [戻り値] x * y を計算して得られる分数

Fraction frcMul(Fraction x, Fraction y) {
	Fraction multiplied;

	int numerator = frcGetNumerator(x) * frcGetNumerator(y);
	int denominator = frcGetDenominator(x) * frcGetDenominator(y);
	multiplied = frcCreate(numerator, denominator);

	return (multiplied);
}

/*========================================*/
// 分数xとyの除算結果を返す
//   [引　数] x, y : 除算対象となる分数
//   [戻り値] x / y を計算して得られる分数
Fraction frcDiv(Fraction x, Fraction y) {
	// 分数の割り算は逆数の掛け算なのでfrcMul()が使える
	int numeratorY = frcGetDenominator(y);
	int denominatorY = frcGetNumerator(y);
	Fraction reciprocalY = frcCreate(numeratorY, denominatorY);

	Fraction isDivision = frcMul(x, reciprocalY);

	return (isDivision);
}

/*========================================*/
// 分数xの既約分数を返す
//   [引　数] x : 約分対象となる分数
//   [戻り値] xの既約分数
Fraction frcReduction(Fraction x) {
	int numerator = frcGetNumerator(x);
	int denominator = frcGetDenominator(x);
	// 分母と分子の最大公約数を求める
	int gcm = getGcm(numerator, denominator);
	// 分母と分子を最大公約数で割る
	numerator /= gcm;
	denominator /= gcm;

	Fraction result = frcCreate(numerator, denominator);

	return (result);
}

/*========================================*/
// mとnの最大公約数を正数で返す
//   [引　数] m, n : 最大公約数を求める対象となる整数
//   [戻り値] mとmの最大公約数
int getGcm(int m, int n) {
	int r;

	// 最大公約数を正数にするため、m,nの絶対値をとる
	m = abs(m);
	n = abs(n);

	r = m % n;
	while (r != 0) {
		m = n;
		n = r;
		r = m % n;
	}
	return (n);
}

/*========================================*/
// mとnの最小公倍数を整数で返す
//   [引　数] m, n : 最小公倍数を求める対象となる整数
//   [戻り値] mとmの最小公倍数
int getLcm(int n, int m) {
	int x = n * m;
	int gcm = getGcm(n, m);

	return (x / gcm);
}

/*========================================*/
// 分数xを a/b の形で表示する（分数の値が負になるとき、符号は分子につける）
//   [引　数] x : 表示する分数
void frcPrint(Fraction x) {
	int n, d;

	n = frcGetNumerator(x);
	d = frcGetDenominator(x);

	if (n * d < 0) {
		// n * dがマイナスの時 = nかdのどちらかがマイナスの時
		// 分子にマイナスをつけ直し、分母の値はその絶対値にする
		n = -abs(n);
		d = abs(d);
	} else {
		n = abs(n);
		d = abs(d);
	}

	if (n == 0 || d == 1) {
		// 分子が0か分母が１の時は(整数になる場合)
		// 分子の値を出力する
		printf("%d", n);
	} else {
		// そうでない場合、
		// n/dの形式で出力する
		printf("%d/%d", n, d);
	}

	return;
}
