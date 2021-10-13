#include <stdio.h>
#include <stdlib.h>

int openFileCheck(FILE *file);

int main(int argc, char *argv[]) {
	FILE *file1 = NULL, *file2 = NULL;
	int optionFlag = 0;

	if (argc > 2) {
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
					if (openFileCheck(file1) == 1) {
						exit(1);
					}
				} else if (file2 == NULL) {
					// コピーされる側は書き込みモード
					file2 = fopen(argv[ i ], "w");
					if (openFileCheck(file2) == 1) {
						fclose(file1);
						exit(1);
					}
				}
			} else if (argc >= 4) {
				if (argv[ i ][ 0 ] == '-') {
					if (argv[ i ][ 1 ] != 'a' || optionFlag != 0) {
						fprintf(stderr, "オプションが間違っています\n");
						return (1);
					}
					optionFlag = 1;
				} else if (argv[ i ][ 0 ] != '-') {
					// オプションで無い場合(ファイルの場合)
					if (file1 == NULL) {
						// 書き込みする側は読取モード
						file1 = fopen(argv[ i ], "r");
						if (openFileCheck(file1) == 1) {
							exit(1);
						}
					} else if (file2 == NULL) {
						// 書き込みされる側は追加書き込みモード
						file2 = fopen(argv[ i ], "a");
						if (openFileCheck(file2) == 1) {
							fclose(file1);
							exit(1);
						}
					}
				}
			}
		}

		// 書き込み処理
		int ch;
		while ((ch = fgetc(file1)) != EOF) {
			fprintf(file2, "%c", ch);
		}
		fclose(file1);
		fclose(file2);
	} else {
		fprintf(stderr, "引数の指定に誤りがあります\n");
		return (1);
	}

	return 0;
}

int openFileCheck(FILE *file) {
	if (file == NULL) {
		printf("ファイルをオープンできませんでした\n");
		return (1);
	}

	return (0);
}