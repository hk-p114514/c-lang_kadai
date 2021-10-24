#include <stdio.h>

int main() {
	printf("100\n");
	char last[2][100] =  {
		"ABC",
		"ABCD"
	};

	char first[2][100] = {
		"GGG", 
		"TTTT"
	};

	for (int i = 0; i < 100; i++) {
		printf("%d %s %s %d %d %d\n", i + 1, last[(i + 1) % 2], first[(i + 1) % 2], i + 1, i + 1, i + 1);
	}

	return (0);
}