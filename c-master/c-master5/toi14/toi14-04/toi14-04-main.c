#include <stdio.h>

extern int data[ 1000 ];

int input(int data[]);
int sum(int n);

int main() {
	int n = input(data);

	// 合計を求める
	int getSum = sum(n);

	// 平均を求める
	int avg = getSum / n;

	printf("合計 : %d\n", getSum);
	printf("平均 : %d\n", avg);

	return (0);
}