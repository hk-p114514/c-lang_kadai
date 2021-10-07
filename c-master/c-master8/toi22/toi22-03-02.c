#include <stdio.h>

int main() {
	FILE *fp1 = fopen("number.bin", "r");
	FILE *fp2 = fopen("rebmun.txt", "w");

	if (fp1 == NULL || fp2 == NULL) {
		fprintf(stderr, "ファイルをオープンできませんでした\n");
		return (1);
	}

	int n;
	char buff[ 1024 ];
	int read = 1;

	while (fread(&n, sizeof(int), read, fp1) >= read) {
		fprintf(fp2, "%d\n", n);
	}

	fclose(fp1);
	fclose(fp2);

	return (0);
}