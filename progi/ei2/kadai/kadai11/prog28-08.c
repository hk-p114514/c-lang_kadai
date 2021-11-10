#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **allocWords(int *n);
void freeWords(char **words, int n);
int rbSearch(char *target, char *words[], int n);
int rbSearchRec(char *target, char *words[], int lower, int upper);

int main(int argc, char *argv[]) {
	int pos, n;
	char **words;

	if (argc < 2) {
		fprintf(stderr, "検索する単語をコマンドライン引数で指定してください。\n");
		exit(1);
	}
	words = allocWords(&n); // 単語データを動的領域に読み込む

	pos = rbSearch(argv[ 1 ], words, n);
	printf("Found: %d\n", pos);

	freeWords(words, n); // allocWords()で確保した領域を開放する

	return (0);
}

char **allocWords(int *n) {
	char line[ 256 ], **words;

	return (words);
}

void freeWords(char **words, int n) {

	return;
}

int rbSearch(char *target, char *words[], int n) {
	return (rbSearchRec(target, words, 0, n - 1));
}

int rbSearchRec(char *target, char *words[], int lower, int upper) {
}
