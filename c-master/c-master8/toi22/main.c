#include <stdio.h> //  ファイルに関して定義されているヘッダファイル
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *in_file;               //  入力ファイルへのファイルポインタ
	int ch;                      //  データを入力する変数
	char *filename = "file.txt"; //  データを入力するファイル

	in_file = fopen(filename, "w"); //  ファイルのオープン
	if (in_file == NULL) {
		printf("%sがオープンできませんでした。\n", filename);
		exit(8); //  異常終了である非ゼロを返してプログラム終了
	}

	char message[] = "Hello World\nThis is a test message\nfor main.c"; //
	int numbers[ 100 ];

	for (int i = 0; i < 100; i++) {
		numbers[ i ] = i; //
	}

	// fprintf(in_file, "Hello World\n");
	fwrite(message, sizeof(char), strlen(message), in_file);
	fwrite(numbers, sizeof(int), sizeof(numbers) / sizeof(numbers[ 0 ]), in_file);

	fclose(in_file); //  ファイルのクローズ

	return (0);
}
