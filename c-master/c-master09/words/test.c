#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **allocwords(int *line_nums);

int main() {
	int *n;
	allocwords(n);

	printf("input : %d\n", n);

	return (0);
}

char **allocwords(int *line_nums) {
	// 入力用、動的メモリ用の変数を用意する
	char buff[ 1024 ];
	int n;
	char **p;
	// 入力を受け取る
	// 入力する文字列の個数
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d", &n);

	// 動的メモリにn個の領域を確保する
	p = (char **)malloc(sizeof(char *) * n);

	if (p == NULL) {
		fprintf(stderr, "メモリを確保できませんでした\n");
		exit(1);
	}

	for (int i = 0; i < n; i++) {
		char s[ 1024 ];
		// 入力を受け取る
		fgets(buff, sizeof(buff), stdin);
		strcpy(s, buff);

		// 文字列の長さを取得する
		int len = strlen(s);

		// 動的メモリを確保する
		p[ i ] = (char *)malloc(sizeof(char) * len);

		// エラーチェック
		if (p[ i ] == NULL) {
			for (int j = 0; j < i; j++) {
				free(p[ i ]);
			}
			free(p);
			fprintf(stderr, "メモリを確保できませんでした。\n");
			exit(1);
		}

		// 動的メモリに格納する
		strcpy(p[ i ], s);
		printf("input : %s\n", p[ i ]);
	}

	return (p);
}