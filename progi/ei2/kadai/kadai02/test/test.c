#include <stdio.h>
#include <stdlib.h>

void paintMark();
void prog13Input();
void printMaxSquare();

int main() {
	printMaxSquare();

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

void printMaxSquare() {
	int size = 50;
	int min = ' ';
	int max = '~';
	int between = max - min;
	char start = 'A';

	for (int i = 0; i < size; i++) {
		// Aから順に文字を書く
	}
}
