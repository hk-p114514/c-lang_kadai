#include "queue.h"
#include "stack.h"
#include <stdio.h>
#include <string.h>

/*
規則1 : 文字列は入力された順に連結する。但し、先頭の+,-は連結の際削除する
規則2 : 先頭が+で始まる文字列はそのまま、-で始まる文字列は文字列を逆順にして連結する
規則3 : 先頭が+,-以外で始まる文字列は無視する。
*/
int main() {
	int n;
	char buff[ 256 ];

	// 文字列の個数を入力
	// printf("Input n : ");
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d", &n);

	// 文字を格納するキュー
	Queue q;
	initQueue(&q);

	for (int i = 0; i < n; i++) {
		// 文字列を受け取る
		char str[ 256 ];
		// printf("Input string[%d] : ", i);
		fgets(buff, sizeof(buff), stdin);
		sscanf(buff, "%s", str);

		if (strlen(str) > 1) {
			if (str[ 0 ] == '+') {
				// そのまま連結
				for (int j = 1; str[ j ] != '\0'; j++) {
					enQueue(&q, str[ j ]);
				}
			} else if (str[ 0 ] == '-') {
				// 逆順で連結

				Stack s;
				initStack(&s);
				for (int j = 1; str[ j ] != '\0'; j++) {
					// 逆順になるようにスタックに文字を格納する
					push(&s, str[ j ]);
				}

				int data;
				int status = pop(&s, &data);
				while (status == 1) {
					enQueue(&q, data);
					status = pop(&s, &data);
				}
			}
		}
	}

	int data;
	int status = deQueue(&q, &data);
	while (status == 1) {
		putchar(data);
		status = deQueue(&q, &data);
	}
	putchar('\n');

	return (0);
}