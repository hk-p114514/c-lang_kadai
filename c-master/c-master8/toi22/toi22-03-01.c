#include <stdio.h>
int openFileCheck(FILE *file);

int main() {
	char *filename1 = "number.txt";
	char *filename2 = "number.bin";

	FILE *file1 = fopen(filename1, "r");
	if (openFileCheck(file1)) {
		return (1);
	}

	FILE *file2 = fopen(filename2, "w");
	if (openFileCheck(file2) == 1) {
		fclose(file1);
	}

	// ファイルをまっさらな状態にする
	fprintf(file2, "");
	fclose(file2);

	// ファイルを開き直す
	file2 = fopen(filename2, "a");

	if (openFileCheck(file2) == 1) {
		fclose(file2);
		return (1);
	}

	int ch;
	char buff[ 1024 ];
	while (fgets(buff, sizeof(buff), file1) != NULL) {
		sscanf(buff, "%d", &ch);
		fwrite(&ch, sizeof(int), 1, file2);
	}
	fclose(file1);
	fclose(file2);

	return (0);
}

int openFileCheck(FILE *file) {
	if (file == NULL) {
		printf("ファイルをオープンできませんでした\n");
		return (1);
	}

	return (0);
}