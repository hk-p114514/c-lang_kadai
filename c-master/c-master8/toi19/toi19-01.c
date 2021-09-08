#include <stdio.h>
#define PRODUCTS 4

int main(int argc, char const *argv[]) {
	int price[ PRODUCTS ] = {100, 30, 100, 15000};
	char products[ PRODUCTS ][ 100 ] =
	    {"りんご", "バナナ", "チェリー", "タスマニアデビル"};

	int i;
	int cost = 0;
	if (argc <= 1 || argv[ 1 ][ 0 ] != '-') {
		printf("オプションがないかまたは不正です。\n");
		printf("正しく入力して下さい。\n");
	} else {
		i = 1; // カウンタ変数の初期化

		// 消費税の直前までオプションを確認する
		while (argc > i && argv[ i ][ 0 ] == '-') {
			// 購入する個数を求める
			int buy = 1;
			char c;
			sscanf(argv[ i ], "-%c%d", &c, &buy);
			char target = argv[ i ][ 1 ];
			if (target == 'a') {
				cost += price[ 0 ];
			} else if (target == 'b') {
				cost += price[ 1 ];
			} else if (target == 'c') {
				cost += price[ 2 ];
			} else if (target == 't') {
				cost += price[ 3 ];
			} else {
				printf("オプションとして使用できません。\n");
			}
			i++;
		}

		printf("cost : %d\n", cost);
	}

	return (0);
}
