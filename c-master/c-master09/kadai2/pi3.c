// atan(x)の級数展開によりπを求める
/*
 * atan(π/4) = 1 なので、
 * (π/4) = atan(1)より、
 * π = 4 * atan(1) = 4{1 - (1/3) + (1/5) - (1/7) ... + (-1)^n * (1/2n+1) + ...}
 * で計算できる。 なお、この式は無限級数となるので、どの時点で計算を打ち切るか
 * 考える必要がある。
 * (打切り誤差と相対打ち切り誤差)
 * k-1項までの和をd, k項までの和をsとしたとき、
 * |s-d|を打ち切り誤差、(|s-d|)/|d| を相対打ち切り誤差という。
 * 一般に、(|s-d|)/|d| < 必要精度となったとき、計算を打ち切る。
 * 10進6桁程度ならば、必要精度は10^-6とすればよい。
 * この(|s-d|)/|d| < 必要精度　の計算を行う際、実際の値を比較するのではなく、
 * 計算機ε(DBL_EPSILON)を用いて、|s-d| < εとなるような値を求める。
 */
#include <float.h>
#include <math.h>
#include <stdio.h>

int main() {
	double s = 1;                                       // 合計の初期値
	double before = 0;                                  // 前回の合計
	int sign = -1;                                      // 符号の初期値
	int denominator = 3;                                // 分母の初期値
	double requiredAccuracy = 1e-6;                     // 必要精度
	double condition = fabs(s - before) / fabs(before); // 相対打ち切り誤差
	double loss = 0;                                    // 丸め誤差

	// 1 - (1/3)から計算を始める
	// 計算打ち切りの条件には、値そのものの比較ではなく、計算機ε(DBL_EPSILON)を用いる
	do {
		before = s;
		double si = sign * (1.0 / denominator);
		s += si + loss;
		sign *= -1;
		denominator += 2;

		// 条件を更新
		condition = fabs(s - before) / fabs(before);

		// 丸め誤差を更新する
		loss = si - (s - before);
	} while (condition > requiredAccuracy);
	printf("condition        = %.10lf\n", condition);
	printf("requiredAccuracy = %.10lf\n", requiredAccuracy);
	printf("DBL_EPSILON      = %.10lf\n", DBL_EPSILON);

	printf("calc = %.10lf\n", 4 * s);
	printf("M_PI = %.10lf\n", M_PI);

	return 0;
}