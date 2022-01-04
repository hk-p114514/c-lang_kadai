#include "list.h"
#include <hamakou.h>
#include <stdio.h>
#include <stdlib.h>

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
	removeTail(&head); // 末尾のセルを削除

	// 全てのセルを削除するまで、削除を繰り返す
	do {
		printf("LIST => ");
		printList(head); // リストの状態を確認
		putchar('\n');
	} while (removeTail(&head) == 1); // 最後尾のセルを削除

	printf("head : %p\n", head);

	printf("２回目\n");

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
		printf("LIST => ");
		printList(head); // リストの状態を確認
		putchar('\n');
	} while (removeTail(&head) == 1); // 最後尾のセルを削除

	printf("head : %p\n", head);

	return (0);
}
