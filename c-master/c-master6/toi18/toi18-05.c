#include <stdio.h>
#define MAX_NAME (256)

void inputName(char name[]);
void removeLineBreaks(char *name, char *removed);
int findSlash(char name[]);
void rewriteSlash(char name[], int count);

int main() {
	char name[ MAX_NAME ];
	// 名前を入力する
	inputName(name);

	// 最後の改行文字を取り除く
	char removed[ MAX_NAME ];
	removeLineBreaks(name, removed);

	// スラッシュの位置を見つける
	int count;
	count = findSlash(removed);

	// スラッシュを\0に書き換える
	rewriteSlash(removed, count);

	printf("removed = %s\n", removed);

	return (0);
}

void inputName(char name[]) {
	char buff[ MAX_NAME ];

	printf("Input name :");
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%s", name);

	return;
}

void removeLineBreaks(char *name, char *removed) {
	for (int i = 0; *(name + i) != '\0'; i++) {
		*(removed + i) = *(name + i);
	}

	return;
}

int findSlash(char name[]) {
	int i = 0;
	do {
		i++;
	} while (name[ i ] != '/');

	return (i);
}

void rewriteSlash(char name[], int count) {
	name[ count ] = '\0';

	return;
}