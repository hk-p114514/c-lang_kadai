#include <hamako.h>
#include <stdio.h>

#define elem 100

void printStr(char map[][ elem ], int n);

int main() {
	char str[ elem ][ elem ];
	int len, n;
	n = getint("Input n: ");

	for (int i = 0; i < n; i++) {
		len = getstring("string : ", str[ i ]);
	}

	printStr(str, n);

	return (0);
}

void printStr(char map[][ elem ], int n) {
	for (int i = 0; i < n; i++) {
		printf("%s\n", map[ i ]);
	}

	return;
}