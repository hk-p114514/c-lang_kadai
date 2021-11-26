#include <hamakou.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate(char *word, int n);
void anagram(char *word, int n);

main(int argc, char *argv[]) {
	int pos, n;
	char *word;

	if (argc < 2) {
		fprintf(stderr, "アナグラムを作る文字列をコマンドライン引数で指定して下さい。\n");
		exit(1);
	}
	word = argv[ 1 ];
	anagram(word, strlen(word));

	return (0);
}

// 文字列wordの右からn文字分を左回りで1文字回転させる
void rotate(char *word, int n) {
	int len = strlen(word) - 1;
	// 文字列の最後尾の文字を保持する
	char last = word[ len ];
	// 文字列の右からn文字の内、最後尾を除いたn - 1文字を右にずらす
	for (int i = 0; i < n; i++) {
		int p = len - i;
		word[ p ] = word[ p - 1 ];
	}
	// 右からn番目に最後尾だった文字を格納する
	word[ len - (n - 1) ] = last;

	return;
}

void anagram(char *word, int n) {
	// 基底条件：n = 1の時、wordそのもの
	if (n <= 1) {
		printf("%s\n", word);
		return;
	} else {
		// wordの各文字全てが先頭になった時の場合を出す
		for (int i = 0; i < n; i++) {
			anagram(word, n - 1);
			rotate(word, n);
		}
	}

	return;
}
