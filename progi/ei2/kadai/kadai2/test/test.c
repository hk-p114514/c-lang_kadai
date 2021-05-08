#include <stdio.h>

int main() {
	int n = 50;
	char mark = 'a';

	// printf("Input n : ");
	// scanf("%d", &n);

	// printf("Input mark : ");
	// scanf(" %c", &mark);

	int i = 0;
	int j = 0;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (mark + i > 80) {
				printf("%c", mark - i);
			} else {
				printf("%c", mark + i);
			}
		}
		putchar('\n');
	}

	return (0);
}