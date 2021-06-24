#include <stdio.h>
#include <string.h>

int removeLineBreaks(char *name, char *removed);

int main() {
	char name[ 256 ], *mei, *sei;

	// 1. 名前入力
	printf("「名/姓」からなる文字列を入力してください\n");
	printf("［例 Tarou/Hamakou ］: ");
	mei = fgets(name, sizeof(name), stdin);

	// 2. 最後の改行文字を取り除く
	char removed[ 256 ];
	int n; // 最後の改行文字を含まない文字数
	n = removeLineBreaks(name, removed);

	// 3. スラッシュの位置を探す
	char *slashPosition = strchr(removed, '/');
	// *slashPosition => '/'

	// 4. スラッシュの位置を\0に置き換える
	*(slashPosition) = '\0';
	mei = removed;
	printf("removed = %s\n", removed);

	sei = slashPosition;
	// - sei => \0

	if (sei == NULL) {
		printf("入力した文字列に\"/\"が含まれていません。\n");
	} else {
		// *sei = ;
		// sei = ;

		printf("名: %s, 姓: %s\n", mei, sei);
	}

	return (0);
}

int removeLineBreaks(char *name, char *removed) {
	int i;
	for (i = 0; name[ i + 1 ] != '\0'; i++) {
		removed[ i ] = name[ i ];
	}

	return (i + 1);
}