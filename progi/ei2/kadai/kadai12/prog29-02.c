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
	// p -> 次に選ばれる組み合わせの頭の数
	// s -> 組み合わせの添字
	if (r <= 0) {
		/*
		組み合わせのr番目の要素を選ぶとき、添字は0から始まるので
		組み合わせのr番目の要素は、sel[ r - 1 ]、その後、s+1されたsが渡される。
		つまり、r = 0のときのsは、最初に関数が呼び出されたときのrと同じになり、
		それは、表示したい組み合わせの個数と同じになることを表す。
		故に、printSelected()の第２引数にはsを渡せば良いということになる。
		*/
		printSelected(sel, s);
		return;
	}

	// 組み合わせを作る
	// 先頭がi(p<= i < n)の組み合わせを作る
	for (int i = p; i < n; i++) {
		// s番目の要素を選ぶ
		sel[ s ] = i;
		// sの次の要素を選ぶ
		// pをi+1にする、つまり、次に選択される値をi+1~n-1の間に制限する
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
