typedef struct {
	char mark;
	int num;
} Card;

#define CARD_NUMBER (52)
#define CARD_MAX (13)

void cardSet(Card cards[]);
void cardPrint(Card card);
void cardShuffle(Card cards[], int n);
int isOnePair(Card five_card[]);
