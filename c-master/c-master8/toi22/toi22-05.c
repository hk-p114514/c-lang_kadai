#include <stdio.h>

int main(int argc, char const *argv[]) {
	FILE *fp = fopen(argv[ 1 ], "r");

	if (fp == NULL) {
		fprintf(stderr, "Error opening input file.\n");
		return (1);
	}

	int row = 16;

	// アドレス表示
	printf("addr\t\t");
	for (int i = 0; i < row; i++) {
		printf("+%X ", i);
	}
	printf("\t\tキャラクタ");
	putchar('\n');

	int addr = 0x0000;

	while (1) {
		if (feof(fp) || ferror(fp)) {
			break;
		}
		// アドレス表示
		printf("%04X\t\t", addr);

		char data[ 1024 ] = {0};
		int success = fread(data, sizeof(char), 16, fp);
		for (int i = 0; i < success; i++) {
			printf("%02X ", data[ i ]);
			if ((data[ i ] < ' ' || data[ i ] > '~')) {
				data[ i ] = '.';
			}
		}

		// 文字数合わせ
		if (success < row) {
			for (int i = 0; i < row - success; i++) {
				printf("   ");
			}
		}

		printf("\t\t%s", data);
		putchar('\n');
		if (success < row) {
			break;
		}
		addr += 0x0010;
	}

	fclose(fp);

	return 0;
}
