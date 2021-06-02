#include <stdio.h>

#define PART1 7
#define PART2 5
#define PART3 ((PART1) + (PART2))

int main() {
	// 求めたいのは、「7 + 5 * 7 + 5」ではなく「(7 + 5) * (7 + 5)」
	printf("%d * %d = %d\n", PART3, PART3, PART3 * PART3);
	return (0);
}
