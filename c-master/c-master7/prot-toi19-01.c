#include <stdio.h>
/* 各商品の値段 */
#define APPLE_VALUE (100)
#define BANANA_VALUE (30)

int includeTax(int value, int taxRate);

int main(int argc, char *argv[]) {
	// オプションの有無・正誤のチェック
	if (argc <= 1 || argv[ 1 ][ 0 ] != '-') {
		printf("オプションがないかまたは不正です。\n");
		printf("正しく入力して下さい。\n");
	} else {
		// オプションが正しく入力された場合
		char goods;            // 商品を決めるオプション
		int quantity;          // 購入する個数
		int taxRate;           // 税率
		int sum = 0;           // 小計
		int includeTaxSum = 0; // 合計

		// 購入したい商品ごとに処理を振り分ける
		for (int i = 1; i < argc && *argv[ i ] == '-'; i++) {
			switch (*(argv[ i ] + 1)) {
			case 'a':
				/* apple */
				break;
			case 'b':
				/* banana */
				break;
			default:
				printf("該当する単語がありません : %s\n", argv[ i ]);
			}
		}
	}

	return (0);
}

int includeTax(int value, int taxRate) {
	return (value * (taxRate / 100));
}
