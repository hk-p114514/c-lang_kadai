// 中点法によりπを求める
/*
 * 区分求積法において、区間[a,b]における積を求めるとき、
 * 各長方形の高さを、f(Xi)ではなく、f(Xi + (w/2))とする。
 * なおこのwは、区間[a,b]における長方形の横幅である。
 */
#include <math.h>
#include <stdio.h>

#define POW(x) ((x) * (x))

int main() {
	double n = 90000000; // 扇形を分割する数
	double s = 0.0;      // 扇形の面積
	double w = 1 / n;    // n分割する長方形の横幅
	double loss = 0;     // 丸め誤差
	double before = 0;   // 前回の計算結果

	// 中点法によりπを求める
	// このとき、積み残し処理を行う
	for (int i = n - 1; i >= 0; i--) {
		// 前回の計算結果を保存
		before = s;

		// i番目の長方形の高さを求める
		// 高さは、f(Xi)ではなく、f(Xi + (w/2))とする
		double y = sqrt(1 - POW(w * i)) + (w / 2);

		// i番目の長方形の面積を求める
		double si = w * y;

		// 扇形の面積を更新
		// ここで積み残し処理を行う
		s += si + loss;

		// 丸め誤差を更新
		loss = si - (s - before);
	}

	s *= 4; // 扇形の面積を4倍にする

	// 結果を出力
	printf("calc = %.10lf\n", s);
	// M_PIを出力
	printf("M_PI = %.10lf\n", M_PI);

	return 0;
}