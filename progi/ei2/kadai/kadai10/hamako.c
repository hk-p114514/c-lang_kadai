#include "hamako.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 自宅用にgetint()を作成
int getint(char *msg) {
	char line[ 100 ];
	int value;

	while (1) {
		(void)printf("%s", msg);
		(void)fgets(line, sizeof(line), stdin);
		if (sscanf(line, "%d", &value) == 1)
			break;
		line[ strlen(line) - 1 ] = '\0';
		(void)fprintf(stderr, "`%s` is not numerical value\n", line);
	}

	return (value);
}
