#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n;
	char buff[ 1024 ];
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d", &n);

	char *p;
	p = (int(*)[ n ])malloc(sizeof(char) * n);

	for (int i = 0; i < n; i++) {
		// 文字列の入力
		printf("文字列[%d] : ", i);
		char s[ 256 ];
		fgets(buff, sizeof(buff), stdin);
		sscanf(buff, "%s", s);

		// 格納
	}

	return (0);
}