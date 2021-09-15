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

void makeDeckOfPlayerCard(Stack *p1, Stack *p2);
int getCard(Stack *stack, int *number, char *mark);
void game(Stack *p1, Stack *p2);
void printAllCards(int cards[]);
int randInt(int max);
int randCard();

int main() {
	// 乱数の発生系列を実行の度に変更
	srand(time(NULL));

	// 53枚のトランプの数字
	// int cardsNumber[ CARD_NUMBER ];

	// 53枚のトランプのマーク
	// char cardsMark[ CARD_NUMBER ];

	// 各プレイヤーの山
	Stack p1, p2;
	initStack(&p1);
	initStack(&p2);

	// 2つの山の作成
	makeDeckOfPlayerCard(&p1, &p2);

	int p1Result = 0, p2Result = 0;
	// ゲーム本体の実装
	game(&p1, &p2);

	// 最終的な得点の表示

	return (0);
}

/*========================================*/

/* game()
    概要:２つの山から１枚ずつカードを引き、
    ゲームの勝敗から得点をつけ、その過程を表示する
*/
// 第1引数: ゲームを行う１０枚のカードの山の２つの内の一つ
// 第2引数: ゲームを行う１０枚のカードの山の２つの内の一つ
// 第3引数: プレイヤー１の得点
// 第4引数: プレイヤー２の得点
// 返り値  : なし
void game(Stack *p1, Stack *p2) {
	printf("=====game start=====\n");
	int count = 1;

	int card1, card2;
	char mark1, mark2;

	// 各プレイヤーの得点を初期化
	int p1Result = 0;
	int p2Result = 0;

	// pop(p1, &card1);
	// int state = pop(p2, &card2);
	getCard(p1, &card1, &mark1);
	int state = getCard(p2, &card2, &mark2);

	// プレイヤー2の山がなくなるまで
	while (state == 1) {
		// ゲームのカウント
		printf("(%2d回目) ", count);

		// 各プレイヤーのカードを表示する
		if (card1 != JOKER_CARD && card2 != JOKER_CARD) {
			// ゲームにジョーカーが含まれない場合
			printf("PLAYER1: %c[%2d]", mark1, card1);

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

			printf("PLAYER2: %c[%2d]", mark2, card2);
		} else {
			char space[] = "    ";
			if (card1 == JOKER_CARD) {
				p1Result++;
				printf("PLAYER1: J%s", space);
				printf(" > ");
				printf("PLAYER2: %c[%2d]", mark2, card2);
			} else if (card2 == JOKER_CARD) {
				p2Result++;
				printf("PLAYER1: %c[%2d]", mark1, card1);
				printf(" < ");
				printf("PLAYER2: J%s", space);
			}
		}

		// 総得点を表示する
		printf("  総得点 - PLAYER1: %2d, PLAYER2: %2d\n", p1Result, p2Result);

		getCard(p1, &card1, &mark1);
		state = getCard(p2, &card2, &mark2);
		count++;
	}

	putchar('\n');
	printf("PLAYER1の得点: %2d\n", p1Result);
	printf("PLAYER2の得点: %2d\n", p2Result);

	return;
}

/* getCard()
    概要:山からカードを一枚引き、その結果を伝える
*/
// 第1引数: カードの山(Stack)
// 第2引数: 引いたカードの数字
// 第3引数: 引いたカードのマーク
// 返り値  : 正常終了：1、スタック・アンダーフロー・0
int getCard(Stack *stack, int *number, char *mark) {
	int state;
	char marks[] = {'H', 'D', 'S', 'C'};
	state = pop(stack, number);
	if (*number != -1) {
		*mark = marks[ randInt(4 - 1) ];
	}

	return (state);
}

/* makeDeckOfPlayerCard()
    概要:53枚のトランプの山から10枚の山を2つ作る
*/
// 第1引数: 10枚の山を作り出すもとの53枚の山
// 第2引数: プレイヤー１の山
// 第３引数:　　プレイヤー２の山
// 返り値  : なし
void makeDeckOfPlayerCard(Stack *p1, Stack *p2) {
	for (int i = 0; i < PLAYER_CARD; i++) {
		push(p1, randCard());
	}

	for (int j = 0; j < PLAYER_CARD; j++) {
		// push(p2, deck[ j + PLAYER_CARD ]);
		// if (randInt(53) != 0) {
		// 	push(p2, randInt(13));
		// } else {
		// 	push(p1, -1);
		// }
		push(p2, randCard());
	}

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

/* randCard()
    概要:-1,1~13の内ランダムな値を返す
*/
// 第1引数: なし
// 返り値  : 生成した値
int randCard() {
	if (randInt(52) != 0) {
		return (1 + rand() % 13);
	} else {
		return (-1);
	}
}

void printAllCards(int cards[]) {
	for (int i = 0; i < CARD_NUMBER; i++) {
		printf("card[ %2d ] = %2d\n", i, cards[ i ]);
	}

	return;
}
