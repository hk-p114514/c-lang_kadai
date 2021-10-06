#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *filename[]) {
	FILE *fp;

	fp = fopen(filename[ 1 ], "r"); // ファイルのオープン

	if (fp == NULL) {
		printf("%sがオープンできませんでした。\n", filename);
		exit(8); //  異常終了である非ゼロを返してプログラム終了
	}

	// ファイルの文字数と行数をカウント
	int count = 0;
	int line = 0;
	char ch;

	while (fscanf(fp, "%c", &ch) != EOF) {
		count++;
		if (ch == '\n') {
			line++;
		}
	}
	putchar('\n');
	fclose(fp);

	printf("文字数 : %d\n", count);
	printf("行数: %d\n", line);

	return 0;
}
