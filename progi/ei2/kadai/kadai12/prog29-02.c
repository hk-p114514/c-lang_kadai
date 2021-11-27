// #include <hamakou.h>
#include <stdio.h>
#include <stdlib.h>

void printCombi(int n, int r);
void printCombiRec(int n, int r, int p, int s, int sel[]);
void printSelected(int sel[], int n);

int main(int argc, char *argv[]) {
	int n, r;

	if (argc < 3) {
		fprintf(stderr, "第1引数にnを、第2引数にrを指定してください。\n");
		exit(1);
	}
	sscanf(argv[ 1 ], "%d", &n);
	sscanf(argv[ 2 ], "%d", &r);

	printCombi(n, r);

	return (0);
}

void printCombi(int n, int r) {
	int sel[ 100 ];

	printCombiRec(n, r, 0, 0, sel);
}

// 0~n-1の連続したn個の整数の中から、r個を選ぶ組み合わせを全て表示する
void printCombiRec(int n, int r, int p, int s, int sel[]) {
	/*
	基底条件：r = 0のとき、つまり、
	r = 1で組み合わせの最後の要素を選んだ後に作った組み合わせを表示する
	*/

	if (r == 0) {
		printSelected(sel, s);
		return;
	}

	for (int i = p; i < n; i++) {
		sel[ s ] = i;
		printCombiRec(n, r - 1, i + 1, s + 1, sel);
	}

	return;
}

void printSelected(int sel[], int n) {
	int i;

	for (i = 0; i < n; i++) {
		printf("%d ", sel[ i ]);
	}
	printf("\n");

	return;
}
