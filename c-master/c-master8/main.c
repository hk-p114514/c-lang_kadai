#include <stdio.h> //  ファイルに関して定義されているヘッダファイル
#include <stdlib.h>

int main() {
	FILE *in_file;               //  入力ファイルへのファイルポインタ
	int ch;                      //  データを入力する変数
	char *filename = "file.txt"; //  データを入力するファイル

	in_file = fopen(filename, "w"); //  ファイルのオープン
	if (in_file == NULL) {
		printf("%sがオープンできませんでした。\n", filename);
		exit(8); //  異常終了である非ゼロを返してプログラム終了
	}

	// for (int i = 0; i < 1000; i++) {
		fprintf(in_file, "Hello World\n");
	// }

	fclose(in_file); //  ファイルのクローズ

	return (0);
}
