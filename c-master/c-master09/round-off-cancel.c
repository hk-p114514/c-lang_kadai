#include <stdio.h>

int main() {
	int i;
	float sum, work, loss, d;

	sum = loss = 0;
	for (i = 0; i < 10000; i++) {
		work = sum; // 前のループの合計
		d = 0.1 + loss;
		sum += d;
		loss = d - (sum - work); // 足す値 - 実際に加えた数、本来なら0.1になるはず(現在の合計 - 前回の合計)
	}

	printf("0.1を10000回加えると、%gになる。\n", sum);

	return (0);
}
