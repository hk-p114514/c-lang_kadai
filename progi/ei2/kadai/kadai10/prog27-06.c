#include "hamako.h"
#include "queue27.h"
#include <stdio.h>

int main() {
	Queue q;
	int i, num, data, state;

	initQueue(&q); // キューの初期化

	num = getint("キューに格納するデータ数：");

	for (i = 0; i < num; i++) {           // キューに指定した個数のデータを格納する
		data = getint("enQueue data : "); // データ入力
		state = enQueue(&q, data);        // 入力データを格納
	}

	putchar('\n'); // 見やすくするための改行

	state = deQueue(&q, &data); // データの取り出し
	putchar('\n');
	while (state == 1) {                     // キューが空になるまでデータを取り出す
		printf("deQueue data : %d\n", data); // 取り出したデータの表示
		state = deQueue(&q, &data);          // データの取り出し
	}

	freeQueue(&q); // キューの解放(このプログラムではなくても問題)

	return (0);
}
