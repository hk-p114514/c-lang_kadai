#include <stdio.h>

int main() {
	unsigned int n;
	char buff[ 1024 ];

	printf("Input data : ");
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%u", &n);

	// create mask data where only the least significant bit is 1.
	unsigned int mask = 1;

	// Counting one bits
	int count = 0;
	while (n > 0) {
		if (n & mask) {
			count++;
		}
		n >>= 1;
	}

	printf("%u\n", count);

	return (0);
}