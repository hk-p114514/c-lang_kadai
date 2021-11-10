#include "allocwords.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	int n;
	char **p;
	int i = 0;

	// コマンドライン引数の確認
	if (argc <= 1 || argc > 2) {
		// コマンドラインに引数が渡されていない
		fprintf(stderr, "引数を正しく指定してください\n");
		return (1);
	} else {
		if ((p = allocWords(&n)) == NULL) {
			fprintf(stderr, "words allocation failed\n");
			exit(8);
		}

		// 探索
		while (i < n && strcmp(p[ i ], argv[ 1 ]) != 0) {
			i++;
		}

		if (i < n) {
			printf("\nline %d: '%s' found\n", i + 1, argv[ 1 ]);
		} else {
			fprintf(stderr, "\n%s does not found\n", argv[ 1 ]);
		}

		freeWords(p, n);
	}

	return 0;
}
