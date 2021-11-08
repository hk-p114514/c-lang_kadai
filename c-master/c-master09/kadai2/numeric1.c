// 使用している処理系でchar, int, long, long
// longの各型で表せる値の最大値と最小値を表示する 正しい書式制御文字を使う

#include <limits.h>
#include <stdio.h>
int main() {
	printf("char     : %20d to %d\n", CHAR_MIN, CHAR_MAX);
	printf("int      : %20d to %d\n", INT_MIN, INT_MAX);
	printf("long     : %20ld to %ld\n", LONG_MIN, LONG_MAX);
	printf("long long: %lld to %lld\n", LLONG_MIN, LLONG_MAX);

	return 0;
}