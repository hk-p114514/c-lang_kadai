#include <stdio.h>
#include <stdlib.h>
// #include <time.h>

void paintMark();
void prog13Input();
double getRandom(int isFloor, double max, double min);

int main() {

	return (0);
}

void prog13Input() {
	// 入力するデータ数
	int n = 100;
	printf("%d\n", n);

	// 実際に入力する動作
	for (int i = 0; i < n; i++) {
	}
}

void paintMark() {
	// 表示する四角形の一辺の長さ（文字数）
	int n = 10000;

	// 範囲外
	// 一番目に表示される文字
	char mark = 'a';

	for (int i = 0; i < n; i++) {

		// printf("%d,", i);
		// printf("(+)%d | (-)%d:", mark + i, mark - i);

		for (int j = 0; j < n; j++) {
			if (mark + i == 127) {
				// スペースなのはわかりにくいので別の文字に置き換え
				printf("%c", 's');
			} else if (mark + i > 32 && mark + i < 127) {
				printf("%c", mark + i);
			} else if (mark - i > 32 && mark - i < 127) {
				printf("%c", mark - i);
			} else {
				// 範囲外
				int scope = '~' - ' ';
				if (mark - i + scope > 32 && mark - i + scope < 127) {
					printf("%c", mark - i + scope);
				} else if (mark + i - scope > 32 && mark + i - scope < 127) {
					printf("%c", mark + i - scope);
				}
			}
		}
		putchar('\n');
	}
}

/*
    getRandom()
    乱数を取得する関数
    第1引数 isFloor :0の場合は倍精度実数を、1の場合は整数を返す
    第2引数 max 	:乱数生成時の最大値
    第3引数 min		:乱数生成時の最小値
    　戻り値 rnd	 :乱数生成時の最小値
*/

double getRandom(int isFloor, double max, double min) {
}