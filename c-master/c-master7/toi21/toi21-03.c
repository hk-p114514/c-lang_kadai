#include "card.h"
#include <stdio.h>

main() {
	Card card[ CARD_NUMBER ];
	int i;

	cardSet(card);           // 52枚のカードをセットする
	cardShuffle(card, 1000); // 1000回シャッフルする

	for (i = 0; i < CARD_NUMBER; i++) {
		printf("%2d : ", i + 1);
		cardPrint(card[ i ]);
	}
}
