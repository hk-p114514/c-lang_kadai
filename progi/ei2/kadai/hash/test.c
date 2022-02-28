#include "hash.h"
#include <stdio.h>

int main() {
	HashEntry tbl[ TBL_SIZE ];
	initHashTable(tbl, TBL_SIZE);
	char key[] = "key";
	char value[] = "value";

	HashElement *elem = createElement(key, value);
	int n = hash(key, TBL_SIZE);
	tbl[ n ].element = elem;

	// キーに対応する要素を検索
	printf("%s\n", getValue(tbl, key));

	return (0);
}