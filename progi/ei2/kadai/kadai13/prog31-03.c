#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int bit2int(char *bit, unsigned int dec);

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "２進整数を引数に指定してください。\n");
		exit(1);
	}
	printf("%u\n", bit2int(argv[ 1 ], 0)); // 符号なし10進数を表示

	return (0);
}

// dec は 2進数文字列 bit を符号なし10進数に変換した値
unsigned int bit2int(char *bit, unsigned int dec) {
	int len = strlen(bit);
	int msb = bit[ 0 ] == '1' ? 1 : 0; // 最上位ビット

	if (len <= 0) {
		return (dec);
	}

	if (msb == 1) {
		int add = 1; // 10進数における各桁の重み
		for (int i = 0; i < len - 1; i++) {
			add *= 2;
		}

		dec += add;
	}

	// 最上位ビットを除いて再帰的に処理
	bit = &bit[ 1 ];

	return (bit2int(bit, dec));
}
