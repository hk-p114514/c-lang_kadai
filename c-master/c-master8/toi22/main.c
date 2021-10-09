#include <stdio.h> //  ファイルに関して定義されているヘッダファイル

int main() {
	int n = 100;
	// output data numbers of binaries
	int data[ n ];

	for (int i = 0; i < sizeof(data) / sizeof(data[ 0 ]); i++) {
		data[ i ] = i;
	}

	FILE *f = fopen("test.bin", "w");

	if (f == NULL) {
		fprintf(stderr, "Error opening test file\n");
		return 1;
	}

	fwrite(data, sizeof(int), n, f);

	return (0);
}
