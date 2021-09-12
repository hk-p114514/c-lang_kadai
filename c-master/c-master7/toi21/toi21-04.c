#include "card.h"
#include <stdio.h>
#define HAND_CARD (5)

int main() {
	Card card[ CARD_NUMBER ];
	int i;
	char buff[ 1024 ];

	cardSet(card);           // 52枚のカードをセットする
	cardShuffle(card, 1000); // 1000回シャッフルする

	int drawStart;
	printf("山の何枚目からカードを引きますか? : ");
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d", &drawStart);

	Card five_card[ HAND_CARD ];
	for (int i = 0; i < HAND_CARD; i++) {
		five_card[ i ] = card[ drawStart + i ];
	}

	// ５枚のカードを表示する
	for (int i = 0; i < HAND_CARD; i++) {
		cardPrint(five_card[ i ]);
	}

	if (isOnePair(five_card) == 1) {
		printf("ワンペアです\n");
	} else {
		printf("ワンペアではありません\n");
	}

	return (0);
}
