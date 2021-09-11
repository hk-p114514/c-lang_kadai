#include <stdio.h>
#include <stdlib.h>

int main() {
	int *p;

	// int100個分
	/* 自動キャストされるが、どの型かを明示する事が推奨される */
	p = (int *)malloc(sizeof(int) * 100);

	if (p == NULL) {
		/* エラー処理 */
		return (1);
	}

	/* p[i]のように配列として使える */

	// 使い終わったら必ず返却
	free(p);

	// mallocで二次元配列
	// int a[3][5]; と同じことを malloc()で行う

	// 1プラスすると、int5個分進むポインタ

	p = (int(*)[ 5 ])malloc(sizeof(int) * 3 * 5);
	// int(*p)[ 5 ];

	return (0);
}