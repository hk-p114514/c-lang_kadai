#include <stdio.h>

int main() {
	char *week[ 7 ] =
	    {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

	char **p;
	int i;

	p = week;
	for (i = 0; i < 7; i++) {
		printf("%s\n", *(p));
		p++;
	}

	return (0);
}
