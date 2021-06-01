#include <stdio.h>
#define DEBUG

extern int data[ 1000 ];

int input(int data[]);

int main() {
	int n = input(data);

#ifdef DEBUG
	for (int i = 0; i < n; i++) {
		printf("data[%d] is %d\n", i, data[ i ]);
	}
#endif

	return (0);
}