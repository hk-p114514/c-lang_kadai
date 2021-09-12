#include <stdio.h>
#define PRODUCTS 4

int main(int argc, char const *argv[]) {
	int price[ PRODUCTS ] = {100, 30, 100, 300};
	char products[ PRODUCTS ][ 100 ] = {"りんご", "バナナ", "チェリー", "Done兵衛"};

	int i;
	if (argc <= 1 || argv[ 1 ][ 0 ] != '-') {
		printf("オプションがないかまたは不正です。\n");
		printf("正しく入力して下さい。\n");
	} else {
		i = 1;           // カウンタ変数の初期化
		int taxRate = 0; // 税率
		int sum = 0;     // 合計額

		// 消費税の直前までオプションを確認する
		while (argc > i && argv[ i ][ 0 ] == '-') {
			if (argv[ i ][ 1 ] >= '0' && argv[ i ][ 1 ] <= '9') {
				sscanf(argv[ i ], "-%d", &taxRate);
			} else {
				// 購入する個数を求める
				int count = 1;
				int buy;
				int productNumber = -1;
				char target;
				sscanf(argv[ i ], "-%c%d", &target, &count);
				if (target == 'a') {
					productNumber = 0;
				} else if (target == 'b') {
					productNumber = 1;
				} else if (target == 'c') {
					productNumber = 2;
				} else if (target == 'd') {
					productNumber = 3;
				} else {
					printf("オプションとして使用できません。 : %s\n", argv[ i ]);
				}

				if (productNumber != -1) {
					buy = price[ productNumber ];
					int cost = buy * count;
					sum += cost;

					// 買った商品の情報を表示
					printf(
					    "%15s\t@%3d\t× %3d = %7d\n",
					    products[ productNumber ],
					    price[ productNumber ],
					    count,
					    cost);
				}
			}
			i++;
		}
		int tax = (double)sum * ((double)taxRate / 100.0);
		printf("----------------------------------------\n");
		printf("%s\t\t\t\t\%7d\n", " 小計", sum);
		printf("%s\t\t\t\t\%7d\n", " 消費税", tax);
		printf("========================================\n");
		printf("%s\t\t\t\t\%7d\n", " 合計", sum + tax);
	}

	return (0);
}
