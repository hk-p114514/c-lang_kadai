// 使用している処理系で、float, double,
// long doubleの各型で表すことのできる最大値・最小値、
// 及び計算機ε、10進数で表現できる有効桁数を表示する。
// 正しい書式制御文字を使う
// 桁数は**DIGで得られる
#include <float.h>
#include <stdio.h>

int main() {
	// 各型で表すことのできる最大値・最小値を表示
	printf("float: %.1e to %.1e\n", FLT_MAX, FLT_MIN);
	printf("double: %.1e to %.1e\n", DBL_MAX, DBL_MIN);
	printf("long double: %.1Le to %.1Le\n", LDBL_MAX, LDBL_MIN);

	// 計算機εを表示
	printf("float ε: %.1e\n", FLT_EPSILON);
	printf("double ε: %.1e\n", DBL_EPSILON);
	printf("long double ε: %.1Le\n", LDBL_EPSILON);

	// 10進数で表現できる有効桁数を表示
	printf("float: %d\n", FLT_DIG);
	printf("double: %d\n", DBL_DIG);
	printf("long double: %d\n", LDBL_DIG);

	return 0;
}