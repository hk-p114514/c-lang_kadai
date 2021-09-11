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
#define CARD_NUMBER (53)
#define PLAYER_NUMBER (10)

void makeDeckOfCard(char deck[]);
void makeDeckOfPlayerCard(char deck[], char p1[], char p2[]);
void game(char p1[], char p2[], int *p1Result, int *p2Result);

int main() {
	// 53枚のトランプ
	char cards[ CARD_NUMBER ];

	// 各プレイヤーの山
	char p1[ PLAYER_NUMBER ], p2[ PLAYER_NUMBER ];

	// トランプの作成
	makeDeckOfCard(cards);

	// 2つの山の作成
	makeDeckOfPlayerCard(cards, p1, p2);

	// ゲーム本体の実装

	// 最終的な得点の表示

	return (0);
}

/*========================================*/

/* makeDeckOfCard()
    概要:53枚のトランプの山を作成する
*/
// 第1引数: 要素数53の文字配列
// 返り値  : なし
void makeDeckOfCard(char deck[]) {
	return;
}

/* makeDeckOfPlayerCard()
    概要:53枚のトランプの山から10枚の山を2つ作る
*/
// 第1引数: 10枚の山を作り出すもとの53枚の山
// 第2引数: プレイヤー１の山
// 第３引数:　　プレイヤー２の山
// 返り値  : なし
void makeDeckOfPlayerCard(char deck[], char p1[], char p2[]) {
	return;
}