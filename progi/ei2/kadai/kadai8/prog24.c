/*========================================
    やること:
        53枚のトランプを作成する。
        10枚の山を2つ作る。
        各山を一枚ずつ、後者が0枚になるまでめくる
            - 一枚めくるごとに点数の計算を行い加算処理をする
        最終的な各点数を出力する
========================================*/
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARD_NUMBER (53)
#define CARD_MAX (13)
#define PLAYER_CARD (10)

void makeDeckOfCard(int deck[]);
void makeDeckOfPlayerCard(int deck[], Stack *p1, Stack *p2);
void shuffleCard(int card[], int n);
void game(Stack *p1, Stack *p2, int *p1Result, int *p2Result);
void printCard(int card);
void printAllCards(int cards[]);
int randInt(int max, int min);

int main() {
	// 53枚のトランプ
	int cards[ CARD_NUMBER ];

	// 各プレイヤーの山
	Stack p1, p2;
	initStack(&p1);
	initStack(&p2);

	// トランプの作成
	makeDeckOfCard(cards);

	printf("/*========================================*/\n");

	// 乱数の発生系列を実行の度に変更
	srand(time(NULL));

	// 作成したトランプのシャッフル
	shuffleCard(cards, 1000);

	// 2つの山の作成
	makeDeckOfPlayerCard(cards, &p1, &p2);

	int p1Result, p2Result;
	// ゲーム本体の実装
	game(&p1, &p2, &p1Result, &p2Result);

	// 最終的な得点の表示

	return (0);
}

/*========================================*/

/* makeDeckOfCard()
    概要:53枚のトランプの山を作成する
*/
// 第1引数: 要素数53の整数配列
// 返り値  : なし
void makeDeckOfCard(int deck[]) {
	printf("makeDeckOfCard\n");

	int n = 1;
	for (int i = 0; i < CARD_NUMBER - 1; i++, n++) {
		if (n > 13) {
			n = 1;
		}

		deck[ i ] = n;
	}
	deck[ CARD_NUMBER - 1 ] = -1;

	return;
}

/* makeDeckOfPlayerCard()
    概要:53枚のトランプの山から10枚の山を2つ作る
*/
// 第1引数: 10枚の山を作り出すもとの53枚の山
// 第2引数: プレイヤー１の山
// 第３引数:　　プレイヤー２の山
// 返り値  : なし
void makeDeckOfPlayerCard(int deck[], Stack *p1, Stack *p2) {
	printf("makeDeckOfPlayerCard\n");

	int i;
	for (i = 0; i < PLAYER_CARD; i++) {
		push(p1, deck[ i ]);
	}

	for (int j = 0; j < PLAYER_CARD; j++) {
		push(p2, deck[ j + i ]);
		printf("push : %d\n", deck[ j + i ]);
	}

	return;
}

/* shuffleCard()
    概要:５３枚のカードを指定回数シャッフルする
*/
// 第1引数: ５３枚のカード
// 第2引数: シャッフルする回数
// 返り値  : なし
void shuffleCard(int card[], int n) {
	printf("shuffleCard\n");

	for (int i = 0; i < n; i++) {
		int place1, place2;
		place1 = randInt(0, CARD_NUMBER - 1);
		place2 = randInt(0, CARD_NUMBER - 1);

		int swap = card[ place1 ];

		card[ place1 ] = card[ place2 ];
		card[ place2 ] = swap;
	}

	return;
}

/* game()
    概要:２つの山から１枚ずつカードを引き、
    ゲームの勝敗から得点をつけ、その過程を表示する
*/
// 第1引数: ゲームを行う１０枚のカードの山の２つの内の一つ
// 第2引数: ゲームを行う１０枚のカードの山の２つの内の一つ
// 第3引数: プレイヤー１の得点
// 第4引数: プレイヤー２の得点
// 返り値  : なし
void game(Stack *p1, Stack *p2, int *p1Result, int *p2Result) {
	printf("=====game=====\n");
	int card1, card2;

	pop(p1, &card1);
	int state = pop(p2, &card2);

	// プレイヤー2の山がなくなるまで
	while (state == 1) {
		printf("p1 : %2d\tp2 : %2d\n", card1, card2);
		pop(p1, &card1);
		state = pop(p2, &card2);
	}

	return;
}

/* printCard()
    概要:渡されたカードを改行なしで表示する
*/
// 第1引数: 表示したいカード
// 返り値  : なし
void printCard(int card) {
	char marks[] = {'H', 'D', 'S', 'C'};

	if (card < 0) {
		printf("J");
	} else if (card < 20) {
	}
}

/* randInt()
    概要:min~maxの整数の乱数を返す
*/
// 第1引数: 乱数の最大値
// 第2引数: 乱数の最小値
// 返り値  : 生成した乱数
int randInt(int max, int min) {
	int rnd = min + rand() % (max + 1);

	return (rnd);
}

void printAllCards(int cards[]) {
	for (int i = 0; i < CARD_NUMBER; i++) {
		printf("card[ %2d ] = %2d\n", i, cards[ i ]);
	}

	return;
}