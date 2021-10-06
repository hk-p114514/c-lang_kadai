#include <stdio.h>

int main(void) {
	FILE *fp = NULL;
	unsigned char Array[ 16 ] = {
	    0x01,
	    0x02,
	    0x03,
	    0x04,
	    0x05,
	    0x06,
	    0x07,
	    0x08,
	    0x09,
	    0x0A,
	    0x0B,
	    0x0C,
	    0x0D,
	    0x0E,
	    0x0F,
	    0x10};

	//	バイナリファイルの書き込みでオープン
	fopen_s(&fp, "num.bin", "wb");

	//	ファイルへ書き込み
	fwrite(Array, sizeof(unsigned char), sizeof(Array) / sizeof(Array[ 0 ]), fp);

	fclose(fp);

	return 0;
}