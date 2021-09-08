#include <hamakou.h>
#include <stdio.h>
#include <stdlib.h>

#define N 5 // 列数

int main() {
	int M, i, j;

	// pは要素数Nの1次元配列へのポインタ(2次元配列は要素数Nの1次元配列の配列)
	int(*p)[ N ];

	M = getint("行数：");
	p = (int(*)[ N ])malloc(sizeof(int) * N * M);
	printf("行のサイズ: %d\n", sizeof(*p));

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			p[ i ][ j ] = (i + 1) * (j + 1);
			printf("%4d", p[ i ][ j ]);
		}
		printf("\n");
	}

	free(p);

	return (0);
}
