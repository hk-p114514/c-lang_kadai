#include <stdio.h>
#include <string.h>

void removeLineBreaks(char name[], char removed[]);

int main() {
	char name[ 256 ], *mei, *sei;

	// 1. 名前入力
	printf("「名/姓」からなる文字列を入力してください\n");
	printf("［例 Tarou/Hamakou ］: ");
	mei = fgets(name, sizeof(name), stdin);
	// - mei => aaa/bbb

	// 2. 最後の改行文字を取り除く
	char removed[ 256 ];
	removeLineBreaks(name, removed);

	// 3. スラッシュの位置を探す
	char *slashPosition = strchr(removed, '/');

	// 4. スラッシュの位置を\0に置き換える
	*(slashPosition) = '\0';

	sei = slashPosition;
	// - sei => \0

	if (sei == NULL) {
		printf("入力した文字列に\"/\"が含まれていません。\n");
	} else {
		*sei = *slashPosition;
		sei = slashPosition;
		printf("名: %s, 姓: %s\n", mei, sei);
	}

	return (0);
}

void removeLineBreaks(char name[], char removed[]) {
	for (int i = 0; name[ i ] != '\n'; i++) {
		removed[ i ] = name[ i ];
	}

	return;
}
