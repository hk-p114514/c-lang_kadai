#include <stdio.h>

main() {
	char *week[ 7 ] =
	    {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

	char **p;
	int i;

	p = week;
	for (i = 0; i < 7; i++) {
		printf("%c%c%c\n", *(*p + 0), *(*p + 1), *(*p + 2));
		p++;
	}

	return (0);
}
