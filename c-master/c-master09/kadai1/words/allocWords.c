#include "allocWords.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    概要:標準入力より文字列を行単位で受け取り、動的メモリで確保した領域に格納する
*/
// 第1引数: 入力した文字列の行数を格納する変数へのポインタ
// 返り値  : 入力行を正常に確保できた - 全入力行を格納した配列へのポインタ
char **allocWords(int *line_nums) {
	// 入力用、動的メモリ用の変数を用意する
	char buff[ 1024 ];
	int n;
	char **p;
	// 入力を受け取る
	// 入力する文字列の個数
	printf("入力する文字列の個数 : ");
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d", &n);

	// 動的メモリにn個の領域を確保する + 番兵用に一つ余分に確保する
	p = (char **)malloc(sizeof(char *) * (n + 1));

	if (p == NULL) {
		fprintf(stderr, "メモリを確保できませんでした\n");
		*line_nums = 0;
		exit(1);
	}

	for (int i = 0; i < n; i++) {
		char s[ 1024 ];
		// 入力を受け取る
		fgets(buff, sizeof(buff), stdin);
		strcpy(s, buff);

		// 文字列の長さを取得する
		int len = strlen(s) - 1;

		// 動的メモリを確保する
		p[ i ] = (char *)malloc(sizeof(char) * len);

		// エラーチェック
		if (p[ i ] == NULL) {
			freeWords(p, i);
			fprintf(stderr, "メモリを確保できませんでした。\n");
			*line_nums = 0;
			return ((char **)NULL);
		}

		// 動的メモリに格納する
		for (int j = 0; j < len; j++) {
			p[ i ][ j ] = s[ j ];
		}
	}
	p[ n ] = (char *)NULL;
	*line_nums = n;

	return (p);
}

/*
    概要:allocWordsで確保した領域を全て解放する
*/
// 第1引数: allocWordsで入力した全文字列を格納している配列へのポインタ
// 返り値  : linesに格納されている文字列の行数
void freeWords(char **lines, int lines_nums) {
	for (int i = 0; i < lines_nums + 1; i++) {
		free(lines[ i ]);
	}
	free(lines);
	return;
}