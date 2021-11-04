#include <stdio.h>

static int n = 0;

int main(void) {
	if (n < 10) {
		printf("Hello world.\n");
		n++;
		main();
	}

	return (0);
}
