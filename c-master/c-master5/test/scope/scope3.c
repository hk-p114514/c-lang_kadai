#include <stdio.h>

int main() {
	char n = 'a';
	printf("n = %c\n", n);
	{
		char n = 'b';
		printf("n = %c\n", n);
		{
			n = 'c';
			printf("n = %c\n", n);
		}
		printf("n = %c\n", n);
	}
	printf("n = %c\n", n);

	return (0);
}