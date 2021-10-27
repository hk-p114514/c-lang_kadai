#include "list.h"
#include <string.h>
// #include <hamakou.h>
#include <stdio.h>
int getint(char *msg);

int main() {
	int data, state, i, n;
	List *head;

	head = getEmptyList(); // headを空リストにする

	n = getint("データの個数："); // リストに格納するデータの個数
	for (i = 1; i <= n; i++) {
		data = getint("Input data: "); // 新しいセルへ格納するデータの入力
		if (insertHead(&head, data) == 0) { // 新しいセルの挿入
			fprintf(stderr, "Error: セルを追加できませんでした。\n");
			break;
		}
		printList(head); // リスト構造に格納されているデータの表示
		putchar('\n');
	}
	putchar('\n'); // 見やすくするために改行

	do {
		printList(head); // リスト構造に格納されているデータの表示
		putchar('\n');
	} while (removeTail(&head) == 1); // 空リストになるまで削除

	return (0);
}

// 自宅用にgetint()を作成
int getint(char *msg) {
	char line[ 100 ];
	int value;

	while (1) {
		(void)printf("%s", msg);
		(void)fgets(line, sizeof(line), stdin);
		if (sscanf(line, "%d", &value) == 1)
			break;
		line[ strlen(line) - 1 ] = '\0';
		(void)fprintf(stderr, "`%s` is not numerical value\n", line);
	}

	return (value);
}