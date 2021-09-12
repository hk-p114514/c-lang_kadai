#include "card.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* cardSet()
    概要:５２枚のカードを用意する
*/
// 第1引数: 用意したカードを格納する配列
// 返り値  : なし
void cardSet(Card cards[]) {
	char marks[] = {'H', 'D', 'S', 'C'};
	int markP = 0;
	int number = 1;

	for (int i = 0; i < CARD_NUMBER; i++, markP++, number++) {
		if (markP >= 4) {
			markP = 0;
		}

		if (number >= 14) {
			number = 1;
		}

		cards[ i ].num = number;
		cards[ i ].mark = marks[ markP ];
	}

	return;
}

/* cardPrint()
    概要:与えられた１枚のカードを表示する
*/
// 第1引数: 表示するカード
// 返り値  : なし
void cardPrint(Card card) {
	printf("%c%d\n", card.mark, card.num);

	return;
}

/* cardShuffle()
    概要:与えられた５２枚のカードを指定回数シャッフルする
*/
// 第1引数: シャッフルする５２枚のカード
// 第2引数: シャッフルする回数
// 返り値  : なし
void cardShuffle(Card cards[], int n) {
	char marks[] = {'H', 'D', 'S', 'C'};
	srand(time(NULL));

	printf("CARD SHUFFLE\n");
	for (int i = 0; i < n; i++) {
		// 0 ~ 51番目のどれかとどれかを入れ替える
		int place1 = rand() % CARD_NUMBER;
		int place2 = rand() % CARD_NUMBER;

		Card swap = cards[ place1 ];

		cards[ place1 ] = cards[ place2 ];
		cards[ place2 ] = swap;
	}

	return;
}

/* isOnePair()
    概要:与えられた５枚のカードの中に、ワンペアがあるかどうか判断する
*/
// 第1引数: ５枚のカードを格納した配列
// 返り値  : ワンペアがある場合___1、ワンペアが無い場合___0
int isOnePair(Card five_card[]) {
	int n = 5;
	int cardCounter[ CARD_MAX ] = {0};

	for (int i = 0; i < n; i++) {
		cardCounter[ five_card[ i ].num ]++;
	}

	int pair = 0;
	for (int i = 0; i < CARD_MAX; i++) {
		if (cardCounter[ i ] == 2) {
			pair++;
		}
	}

	if (pair == 1) {
		return (1);
	} else {
		return (0);
	}
}
