#include <stdio.h>
#include <string.h>

int main() {
	char name[ 256 ], *mei, *sei;

	printf("「名/姓」からなる文字列を入力してください\n");
	printf("［例 Tarou/Hamakou ］: ");

	// nameの先頭アドレスがmeiに格納される
	mei = fgets(name, sizeof(name), stdin);

	// 改行文字を取り除く
	*(mei + strlen(name)) = '\0';

	sei = strrchr(name, '/');

	if (sei == NULL) {
		printf("入力した文字列に\"/\"が含まれていません。\n");
	} else {
		*sei = '\0';
		sei = &*(sei + sizeof(char));
		printf("名: %s, 姓: %s\n", mei, sei);
	}

	return (0);
}
