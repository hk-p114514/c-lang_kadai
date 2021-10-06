#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *filename[]) {
	FILE *fp;

	fp = fopen(filename[ 1 ], "r"); // ファイルのオープン

	if (fp == NULL) {
		printf("%sがオープンできませんでした。\n", filename);
		exit(8); //  異常終了である非ゼロを返してプログラム終了
	}

	fclose(fp);

	return 0;
}
