#include "list.h"
// #include <hamakou.h>
#include <stdio.h>
#include <stdlib.h>

int getint(const char *str);

int main() {
	int data, i, n;
	List *head;

	head = getEmptyList();

	n = getint("データの個数："); // リストに格納するデータの個数
	for (i = 1; i <= n; i++) {
		data = getint("Input data: ");         // 新しいセルへ格納するデータの入力
		if (insertUpOrder(&head, data) == 0) { // 新しいセルを昇順になるようにの挿入
			fprintf(stderr, "Error: セルを追加できませんでした。\n");
			break;
		}
	}
	putchar('\n');

	// 全てのセルを削除するまで、削除を繰り返す
	do {
		printList(head); // リストの状態を確認
		putchar('\n');
	} while (removeTail(&head) == 1); // 最後尾のセルを削除

	return (0);
}

int getint(const char *str) {
	int data;
	printf("%s", str);
	scanf("%d", &data);
	return (data);
}