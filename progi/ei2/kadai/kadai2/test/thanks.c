#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

int main() {
	setlocale(LC_CTYPE, "ja_jp.UTF-8");

	char message[] = "だいすきです、ありがとう";

	// メモリの確保
	size_t capacity = strlen(message) + 1;
	wchar_t *buf = (wchar_t *)malloc(sizeof(wchar_t) * capacity);

	// char -> wchar_t encoding
	int result = mbstowcs(buf, message, capacity);

	if (result <= 0) {
		fprintf(stderr, "Error multiplier\n");

		return EXIT_FAILURE;
	}

	printf("bytes : %lu\n", capacity - 1);
	printf("length: %d\n", result);

	// メモリの確保
	capacity = wcslen(buf) * 6 + 1;
	char *buf2 = (char *)malloc(sizeof(char) * capacity);

	// wchart -> char encoding
	result = wcstombs(buf2, buf, capacity);

	if (result <= 0) {
		fprintf(stderr, "Error multiplier\n");

		return EXIT_FAILURE;
	}

	printf("string: %s\n", buf2);
	printf("first : %lc\n", buf2[ 0 ]);

	return (0);
}