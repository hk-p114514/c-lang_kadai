// #include <hamakou.h>
#include <stdio.h>

int hailstones(int n);

int main() {
	int n, count;
	char buff[ 1024 ];

	printf("nを入力して下さい: ");
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d", &n);

	// n = getint("nを入力して下さい: ");

	printf("\n%d から生成されるから生成される「霞」\n\n", n);

	count = hailstones(n);

	printf("\n合計 %d 個\n", count);

	return (0);
}

/* hailstones()
    概要:渡された整数nより生成される数列を表示し、生成した霰の数を返す
*/
// 第一引数: 整数n
// 返り値  : 生成した霰の数
int hailstones(int n) {
	printf("%d ", n);
	int count = 1;

	while (n != 1) {
		count++;
		if (n % 2 == 0) {
			// n が偶数のとき
			n = n / 2;
		} else {
			// n が奇数のとき
			n = (3 * n) + 1;
		}
		printf("%d ", n);
	}

	return (count);
}