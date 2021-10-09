#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *file1 = NULL, *file2 = NULL;

	for (int i = 1; i < argc; i++) {
		// オプションがあったら、確認の後処理
		/*
		 *  引数を一つ一つ確認していって、
		 * 	ファイル名ならばfile1,file2に指定
		 * 	オプションならば、-aであることを確認する
		 */
		// もし、オプションならば、-aであることを確認する
		if (argc <= 3) {
			// オプションがなければコピーするだけ
			if (file1 == NULL) {
				// コピーする側は読取モード
				file1 = fopen(argv[ i ], "r");
			} else if (file2 == NULL) {
				// コピーされる側は書き込みモード
				file2 = fopen(argv[ i ], "w");
			}
		} else if (argc >= 4) {
			if (argv[ i ][ 0 ] == '-' && argv[ i ][ 1 ] != 'a') {
				fprintf(stderr, "オプションが間違っています\n");
				return (1);
			} else if (argv[ i ][ 0 ] != '-') {
				// オプションで無い場合(ファイルの場合)
				if (file1 == NULL) {
					// 書き込みする側は読取モード
					file1 = fopen(argv[ i ], "r");
				} else if (file2 == NULL) {
					// 書き込みされる側は追加書き込みモード
					file2 = fopen(argv[ i ], "a");
				}
			}
		}
	}

	if (file1 == NULL || file2 == NULL) {
		fprintf(stderr, "ファイルのオープンに失敗しました\n");
		fclose(file1);
		fclose(file2);
		return (1);
	}

	// 書き込み処理
	int ch;
	while ((ch = fgetc(file1)) != EOF) {
		fprintf(file2, "%c", ch);
	}
	fclose(file1);
	fclose(file2);

	return 0;
}
