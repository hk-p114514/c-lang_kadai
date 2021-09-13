#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n;
	char buff[ 256 ];
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d", &n);

	char **p;
	p = (char **)malloc(sizeof(char *) * n);

	if (p == NULL) {
		printf("メモリを確保できませんでした。\n");
		return (1);
	}

	for (int i = 0; i < n; i++) {
		// 文字列の入力
		printf("文字列[%d] : ", i);
		char s[ 256 ];
		fgets(buff, sizeof(buff), stdin);
		strcpy(s, buff);

		int len = strlen(s);

		// 格納
		p[ i ] = (char *)malloc(sizeof(char) * len);

		if (p[ i ] == NULL) {
			for (int j = 0; j < i; j++) {
				free(p[ i ]);
			}
			free(p);
			printf("メモリを確保できませんでした。\n");
			return (1);
		}

		for (int j = 0; j < len; j++) {
			p[ i ][ j ] = s[ j ];
		}
	}

	// 表示
	putchar('\n');
	for (int i = 0; i < n; i++) {
		printf("文字列[%d] : %s", i, p[ i ]);
	}

	for (int i = 0; i < n; i++) {
		free(p[ i ]);
	}

	free(p);

	return (0);
}