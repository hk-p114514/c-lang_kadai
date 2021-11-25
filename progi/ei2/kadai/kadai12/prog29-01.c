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
	int len = strlen(word);
	// 文字列の最後尾の文字を保持する
	char last = word[ len - 1 ];
	// 文字列の右からn文字の内、最後尾を除いたn - 1文字を右にずらす
	// 右からn番目に最後尾だった文字を格納する

	return;
}

void anagram(char *word, int n) {
}
