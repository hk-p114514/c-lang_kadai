#include <stdio.h>
#include <stdlib.h>
int gcm(int m, int n);

int main() {
	char buff[ 1024 ];
	int m, n;

	printf("n1 n2 : ");
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d %d", &m, &n);

	printf("gcm = %d\n", gcm(m, n));

	return (0);
}

// mとnの最大公約数を正数で返す
//   [引　数] m, n : 最大公約数を求める対象となる整数
//   [戻り値] mとmの最大公約数
int gcm(int m, int n) {
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