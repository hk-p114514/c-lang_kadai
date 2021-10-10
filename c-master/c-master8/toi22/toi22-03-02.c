#include <stdio.h>
int openFileCheck(FILE *file);

int main() {
	FILE *fp1 = fopen("number.bin", "r");
	if (openFileCheck(fp1)) {
		return (1);
	}
	FILE *fp2 = fopen("rebmun.txt", "w");
	if (openFileCheck(fp2)) {
		fclose(fp1);
		return (1);
	}

	int n;
	char buff[ 1024 ];
	int read = 1;

	while (fread(&n, sizeof(int), read, fp1) >= 1) {
		fprintf(fp2, "%d\n", n);
	}

	fclose(fp1);
	fclose(fp2);

	return (0);
}

int openFileCheck(FILE *file) {
	if (file == NULL) {
		printf("ファイルをオープンできませんでした\n");
		return (1);
	}

	return (0);
}