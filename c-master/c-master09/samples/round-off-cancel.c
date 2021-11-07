#include <stdio.h>

int main() {
	int i;
	float sum, before, loss, add;

	sum = loss = 0;
	for (i = 0; i < 10000; i++) {
		before = sum; // 前のループの合計
		// d = 0.1
		add = 0.1 + loss;
		sum += add;
		loss = add - (sum - before);
	}

	printf("0.1を10000回加えると、%gになる。\n", sum);

	return (0);
}
