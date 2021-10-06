#include <stdio.h>

int main() {
	FILE *fp1 = fopen("number.txt", "r");
	FILE *fp2 = fopen("rebmun.txt", "w");

	if (fp1 == NULL || fp2 == NULL) {
		fprintf(stderr, "ファイルをオープンできませんでした\n");
		return (1);
	}

	int a, b, c;
	char buff[ 1024 ];

	fread(buff, sizeof(char), 1, fp1);
	sscanf(buff, "%d %d %d", &a, &b, &c);
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);

	fclose(fp1);
	fclose(fp2);

	return (0);
}