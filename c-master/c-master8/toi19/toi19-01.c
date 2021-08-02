#include <stdio.h>

int main(int argc, char const *argv[]) {
	int i;

	if (argc <= 1 || argv[ 1 ][ 0 ] != '-') {
		printf("オプションがないかまたは不正です。\n");
		printf("正しく入力して下さい。\n");
	} else {
		i = 1; // カウンタ変数の初期化
		while (argc > i && argv[ i ][ 0 ] == '-') {
		}
	}

	return (0);
}
