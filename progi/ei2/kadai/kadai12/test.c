#include <stdio.h>

int main() {
	int arr[ 10 ];
	int n = 100;

	for (int i = 0; i < n; i++) {
		printf("arr[%d]=%d\n", i, arr[ i ]);
	}

	return (0);
}