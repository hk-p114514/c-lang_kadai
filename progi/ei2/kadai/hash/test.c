#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash1(char *name, int tbl_size);
int hash2(char *name, int tbl_size);
int hash3(char *name, int tbl_size);

int main() {

	return (0);
}

int hash(char *name, int tbl_size) {
	int hashVal = 0;
	int i = 0;
	int n = strlen(name);

	for (i = 0; i < n; i++) {
		hashVal = (hashVal << 4) + name[ i ];
	}

	return hashVal % tbl_size;
}

int hash2(char *name, int tbl_size) {
	// 論理演算(&や|)を使ったハッシュ関数
	int hashVal = 0;
	int i = 0;
	int n = strlen(name);

	for (i = 0; i < n; i++) {
		hashVal = (hashVal << ((i + 1) % n)) + name[ i ];
	}

	return hashVal % tbl_size;
}

int hash3(char *name, int tbl_size) {
	// ビット演算(^)を使ったハッシュ関数
	int hashVal = 0;
	int i = 0;
	int n = strlen(name);

	for (i = 0; i < n; i++) {
		hashVal ^= name[ i ];
	}

	return hashVal % tbl_size;
}

int hash4(char *name, int tbl_size) {
	// hash1~hash3を組み合わせたハッシュ関数
	int hashVal = 0;
	int i = 0;
	int n = strlen(name);

	for (i = 0; i < n; i++) {
		hashVal = (hashVal << ((i + 1) % n)) + name[ i ];
		hashVal ^= name[ i ];
	}

	return hashVal % tbl_size;
}