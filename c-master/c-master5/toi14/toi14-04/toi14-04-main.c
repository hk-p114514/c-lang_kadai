#include <stdio.h>

extern int data[ 1000 ];

int input(void);
int sum(int n);

int main() {
	int n = input();

	// 合計を求める
	int getSum = sum(n);

	// 平均を求める
	double avg = getSum / (double)n;

	printf("合計 : %d\n", getSum);
	printf("平均 : %g\n", avg);

	return (0);
}