#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char s[ 100 ];
	char buffer[ 100 ];

	fgets(buffer, sizeof(buffer), stdin);
	sscanf(buffer, "%s", s);

	printf("%d\n", strcmp(s, "umaibo"));

	return 0;
}
