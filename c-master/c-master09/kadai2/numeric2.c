// 使用している処理系で、float, double,
// long doubleの各型で表すことのできる最大値・最小値、
// 及び計算機ε、10進数で表現できる有効桁数を表示する。
// 正しい書式制御文字を使う
// 桁数は**DIGで得られる
#include <float.h>
#include <stdio.h>

int main() {
	// 各型で表すことのできる最大値・最小値を表示
	printf("float        : %.6e   to %.6e\n", FLT_MIN, FLT_MAX);
	printf("double       : %.15e  to %.15e\n", DBL_MIN, DBL_MAX);
	printf("long double  : %.18Le to %.18Le\n", LDBL_MIN, LDBL_MAX);

	// 計算機εを表示
	printf("float ε      : %.6e\n", FLT_EPSILON);
	printf("double ε     : %.15e\n", DBL_EPSILON);
	printf("long double ε: %.18Le\n", LDBL_EPSILON);

	// 10進数で表現できる有効桁数を表示
	printf("float        : %d\n", FLT_DIG);
	printf("double       : %d\n", DBL_DIG);
	printf("long double  : %d\n", LDBL_DIG);

	return 0;
}