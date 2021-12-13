#include <stdio.h>
#include <string.h>

int main() {
	char *str = "HelloWorld";
	int n = strlen(str);

	for (int i = 0; i < n; i++) {
		printf("%s\n", str);
		str = &str[ 1 ];
	}

	return 0;
}