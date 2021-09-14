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
#define JOKER_CARD (-1)

void makeDeckOfCard(int cards[], char marks[]);
void makeDeckOfPlayerCard(int deck[], Stack *p1, Stack *p2);
void shuffleCard(int card[], int n);
void game(Stack *p1, Stack *p2, char marks[]);
void printAllCards(int cards[]);
int randInt(int max);

int main() {
	// 乱数の発生系列を実行の度に変更
	srand(time(NULL));

	// 53枚のトランプの数字
	int cardsNumber[ CARD_NUMBER ];

	// 53枚のトランプのマーク
	char cardsMark[ CARD_NUMBER ];

	// 各プレイヤーの山
	Stack p1, p2;
	initStack(&p1);
	initStack(&p2);

	// トランプの作成
	makeDeckOfCard(cardsNumber, cardsMark);

	// 作成したトランプのシャッフル
	shuffleCard(cardsNumber, 1000);

	// 2つの山の作成
	makeDeckOfPlayerCard(cardsNumber, &p1, &p2);

	int p1Result = 0, p2Result = 0;
	// ゲーム本体の実装
	game(&p1, &p2, cardsMark);

	// 最終的な得点の表示

	return (0);
}

/*========================================*/

/* makeDeckOfCard()
    概要:53枚のトランプの山を作成する
*/
// 第1引数: 要素数53の整数配列
// 返り値  : なし
void makeDeckOfCard(int cards[], char marks[]) {
	char exampleMarks[] = {'H', 'D', 'S', 'C'};
	int n = 1, c = 0;
	for (int i = 0; i < CARD_NUMBER - 1; i++, n++, c++) {
		if (n > 13) {
			n = 1;
		}

		if (c >= 4) {
			c = 0;
		}

		cards[ i ] = n;
		marks[ i ] = exampleMarks[ c ];
	}
	cards[ CARD_NUMBER - 1 ] = -1;
	marks[ CARD_NUMBER - 1 ] = 'J';

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
	for (int i = 0; i < PLAYER_CARD; i++) {
		push(p1, deck[ i ]);
	}

	for (int j = 0; j < PLAYER_CARD; j++) {
		push(p2, deck[ j + PLAYER_CARD ]);
	}

	return;
}

/* shuffleCard()
    概要:５３枚のカードを指定回数シャッフルする
*/
// 第1引数: ５３枚のカード
// 第2引数: シャッフルする回数
// 返り値  : なし
void shuffleCard(int cards[], int n) {
	for (int i = 0; i < n; i++) {
		int place1, place2;
		place1 = randInt(CARD_NUMBER - 1);
		place2 = randInt(CARD_NUMBER - 1);

		int swap = cards[ place1 ];

		cards[ place1 ] = cards[ place2 ];
		cards[ place2 ] = swap;
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
void game(Stack *p1, Stack *p2, char marks[]) {
	printf("=====game start=====\n");
	int card1, card2, count = 1;

	// 各プレイヤーの得点を初期化
	int p1Result = 0;
	int p2Result = 0;

	pop(p1, &card1);
	int state = pop(p2, &card2);

	// プレイヤー2の山がなくなるまで
	while (state == 1) {
		// ゲームのカウント
		printf("(%2d回目) ", count);

		// 各プレイヤーのカードを表示する
		if (card1 != JOKER_CARD && card2 != JOKER_CARD) {
			// ゲームにジョーカーが含まれない場合
			printf("PLAYER1: %c[%2d]", marks[ card1 ], card1);

			// カードの大小によって表示するマークを変える
			if (card1 > card2) {
				printf(" > ");
				p1Result++;
			} else if (card1 < card2) {
				printf(" < ");
				p2Result++;
			} else if (card1 == card2) {
				printf(" = ");
			}

			printf("PLAYER2: %c[%2d]", marks[ card2 ], card2);
		} else {
			char space[] = "    ";
			if (card1 == JOKER_CARD) {
				p1Result++;
				printf("PLAYER1: J%s", space);
				printf(" > ");
				printf("PLAYER2: %c[%2d]", marks[ card2 ], card2);
			} else if (card2 == JOKER_CARD) {
				p2Result++;
				printf("PLAYER1: %c[%2d]", marks[ card1 ], card1);
				printf(" < ");
				printf("PLAYER2: J%s", space);
			}
		}

		// 総得点を表示する
		printf("  総得点 - PLAYER1: %2d, PLAYER2: %2d\n", p1Result, p2Result);

		pop(p1, &card1);
		state = pop(p2, &card2);
		count++;
	}

  putchar('\n');
	printf("PLAYER1の得点: %2d\n", p1Result);
	printf("PLAYER2の得点: %2d\n", p2Result);

	return;
}

/* randInt()
    概要:1~maxの整数の乱数を返す
*/
// 第1引数: 乱数の最大値
// 返り値  : 生成した乱数
int randInt(int max) {
	int rnd = rand() % (max + 1);

	return (rnd);
}

void printAllCards(int cards[]) {
	for (int i = 0; i < CARD_NUMBER; i++) {
		printf("card[ %2d ] = %2d\n", i, cards[ i ]);
	}

	return;
}
