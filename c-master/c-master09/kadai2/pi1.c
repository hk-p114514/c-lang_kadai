// 区分求積法によりπを求める
/*
 * 扇形をn個の長方形に分割したとき、
 * i番目の長方形の面積は、Si = (i/n) * sqrt(1 - x^2)で求められる。
 * このSiは円の４分の１の面積なので、4 * Si = piとなる。
 * またこのとき、誤差も４倍になるので、
 * それも考慮してnを決定する必要がある。
 */
// 丸め誤差、情報落ちを考慮し、積み残し処理を行う
#include <math.h>
#include <stdio.h>
#define POW(x) ((x) * (x))

int main() {
	double n = 9000000; // 扇形をn個の長方形に分割する
	double s = 0.0;     // 扇形の面積
	double w = 1 / n;   // n個の長方形の幅
	double loss = 0;    // 丸め誤差
	double before = 0;  // 前回の計算結果

	// 扇形をn個の長方形に分割する
	// このとき、積み残し処理を行う
	for (int i = n - 1; i >= 0; i--) {
		// 前回の計算結果を保存する
		before = s;

		// i番目の長方形の高さを求める
		double y = sqrt(1 - POW(w * i));

		// i番目の長方形の面積を求める
		double si = w * y;

		// 扇形の面積を加算する
		// このとき、積み残し処理を行う
		s += si + loss;

		// 丸め誤差を更新する
		loss = si - (s - before);
	}

	s *= 4; // 扇形の面積を4倍にする

	// 結果を出力
	printf("calc = %.10lf\n", s);
	printf("M_PI = %.10lf\n", M_PI);

	return 0;
}
