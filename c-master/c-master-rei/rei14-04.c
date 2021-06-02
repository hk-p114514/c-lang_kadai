#include <stdio.h>

int up(void);   // 関数プロトタイプ宣言
int down(void); // 関数プロトタイプ宣言

int x, y; // グローバル変数として宣言

int main() {
	int up_dat, down_dat;

	x = 0; // 変数 x を初期化
	y = 0; // 変数 y を初期化

	up_dat = up();

	x = 1023948;

	up_dat = up();

	down_dat = down();

	y = -49823947;

	down_dat = down();

	printf("up_dat   = %2d回\n", up_dat);
	printf("down_dat = %2d回\n", down_dat);

	return (0);
}

int up(void) {
	x++;

	return (x);
}

int down(void) {
	y--;

	return (y);
}
