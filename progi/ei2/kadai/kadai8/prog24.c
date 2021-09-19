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
#define JOKER_CARD (53)
#define SHUFFLE_COUNT (10000)

void game(Stack *p1, Stack *p2);
void makeDeck(int deck[]);
void makeDeckOfPlayerCard(int deck[], Stack *p1, Stack *p2);
int getCard(Stack *player, int *number, char *mark);
void shuffleCard(int cards[], int n);
void swap(int *a, int *b);
int randInt(int max);
void printAllCards(int cards[]);

int main() {
	// 乱数の発生系列を実行の度に変更
	srand(time(NULL));

	// 53枚のカードの山
	int deck[ CARD_NUMBER ];

	makeDeck(deck);

	shuffleCard(deck, SHUFFLE_COUNT);

	// 各プレイヤーの山
	Stack p1, p2;
	initStack(&p1);
	initStack(&p2);

	// プレイヤーの二つの山を作る
	makeDeckOfPlayerCard(deck, &p1, &p2);

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
				p1Result += 2;
			} else if (card1 < card2) {
				printf(" < ");
				p2Result += 2;
			} else if (card1 == card2) {
				printf(" = ");
				p1Result++;
				p2Result++;
			}

			printf("PLAYER2: %c[%2d]", mark2, card2);
		} else {
			char space[] = "    ";
			if (card1 >= JOKER_CARD) {
				p1Result += 2;
				printf("PLAYER1: J%s", space);
				printf(" > ");
				printf("PLAYER2: %c[%2d]", mark2, card2);
			} else if (card2 >= JOKER_CARD) {
				p2Result += 2;
				printf("PLAYER1: %c[%2d]", mark1, card1);
				printf(" < ");
				printf("PLAYER2: J%s", space);
			}
		}

		// 総得点を表示する
		printf("  総得点 - PLAYER1: %2d, PLAYER2: %2d\n", p1Result, p2Result);

		// pop(p1, &card1);
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
    概要:山から引いたカードの数字とマークを伝える
*/
// 第1引数: カードの山
// 第2引数: 引いたカードの数字
// 第3引数: 引いたカードのマーク
// 戻り値：正常終了：1、スタック・アンダーフロー・0
int getCard(Stack *player, int *number, char *mark) {
	int card = 0;
	int state;
	char marks[] = {'H', 'D', 'S', 'C'};

	state = pop(player, &card);

	if (card < CARD_NUMBER) {
		// ジョーカーでなければ
		*mark = marks[ card % 4 ];
		*number = 1 + card % CARD_MAX;
	} else if (card == JOKER_CARD) {
		*number = JOKER_CARD;
	}

	return (state);
}

/* makeDeck()
    概要:53枚のトランプの山を作成する
*/
// 第1引数: 要素数53の整数配列
// 返り値  : なし
void makeDeck(int cards[]) {

	// 53枚のカードを作る
	for (int i = 0; i < CARD_NUMBER; i++) {
		cards[ i ] = i + 1;
	}

	return;
}

/* makeDeckOfPlayerCard()
    概要:53枚のトランプの山から10枚の山を2つ作る
*/
// 第1引数: 10枚の山を作り出すもとの53枚の山
// 第2引数: プレイヤー１の山
// 第３引数:プレイヤー２の山
// 返り値  : なし
void makeDeckOfPlayerCard(int deck[], Stack *p1, Stack *p2) {
	for (int i = 0; i < PLAYER_CARD; i++) {
		// 山札の枚数(10枚)分選択するカードをずらす
		push(p1, deck[ i ]);
		push(p2, deck[ i + PLAYER_CARD ]);
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
	printf("shuffleCard\n");

	for (int i = 0; i < n; i++) {
		int place1, place2;
		place1 = randInt(CARD_NUMBER - 1);
		place2 = randInt(CARD_NUMBER - 1);

		swap(&cards[ place1 ], &cards[ place2 ]);
	}

	return;
}

/* swap()
    概要:二つの変数の内容を置換する
*/
// 第1,2引数: 置換したい変数
// 返り値  : なし
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;

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
