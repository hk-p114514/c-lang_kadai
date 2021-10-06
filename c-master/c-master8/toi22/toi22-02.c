#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *file1 = NULL, *file2 = NULL;

	for (int i = 0; i < argc; i++) {
		if (argc <= 3) {
			// オプションがなければコピーするだけ
		} else if (argc >= 4) {
			// オプションがあったら、確認の後処理
			/*
			 *  引数を一つ一つ確認していって、
			 * 	ファイル名ならばfile1,file2に指定
			 * 	オプションならば、-aであることを確認する
			 */
			// もし、オプションならば、-aであることを確認する
			if (argv[ i ][ 0 ] == '-') {
				fprintf(stderr, "オプションが間違っています\n");
				return (1);
			} else {
				// オプションで無い場合(ファイルの場合)
				if (file1 == NULL) {
					// 書き込みする側は読取モード
					file1 = fopen(argv[ i ], "r");
				} else if (file2 == NULL) {
					// 書き込みされる側は書き込みモード
					file2 = fopen(argv[ i ], "a");
				}
			}
		}
	}

	if (file1 == NULL || file2 == NULL) {
		printf("ファイルのオープンに失敗しました\n");
		return (1);
	}

	return 0;
}
