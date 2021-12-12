#include <stdio.h>
#include <stdlib.h>

int combi(int n, int r);
void combiTail(int n, int r, long long ans[]);

int main(int argc, char *argv[]) {
	int n, r;

	if (argc < 3) {
		fprintf(stderr, "第1引数にnを、第2引数にrを指定してください。\n");
		exit(1);
	}
	sscanf(argv[ 1 ], "%d", &n);
	sscanf(argv[ 2 ], "%d", &r);

	printf("%d\n", combi(n, r));

	return (0);
}

// パスカルの三角形の上からn段目、左からr番目の値
int combi(int n, int r) {
	// nCr の分子と分母が大きな値になるので long long で計算する
	long long ans[ 2 ] = {1, 1}; // ans[0] … nCr の分子, ans[1] … nCr の分母

	// nCr = nCn-r の関係があるので r と n - r の小さい方で計算
	if (r > n - r) {
		r = n - r;
	}
	combiTail(n, r, ans);

	return (ans[ 0 ] / ans[ 1 ]);
}

// ans[0] は nCr の分子、ans[1]は nCr の分母
void combiTail(int n, int r, long long ans[]) {
	/*
	 * パスカルの三角形の上からn段目、左からr番目の値は
	 * nCrの計算結果になっている。
	 * nCr = n*(n-1)*(n-2)/r*(r-1)*(r-2)であるので、
	 * r=0になるまでnとrをans[]のそれぞれに掛け、nとrを1ずつ減らしていけば良い。
	 */
	if (r <= 0) {
		return;
	} else {
		ans[ 0 ] *= n;
		ans[ 1 ] *= r;
		n--;
		r--;
		combiTail(n, r, ans);
	}

	return;
}
