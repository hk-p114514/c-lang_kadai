// #include "hamako.h"
#include "list.h"
#include <stdio.h>

int main() {
	int data, state, i, n;
	List *head;

	head = getEmptyList(); // headを空リストにする

	printf("データの個数：");
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		printf("Input data: ");
		scanf("%d", &data);
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
	} while (removeHead(&head) == 1); // 空リストになるまで削除

	return (0);
}
