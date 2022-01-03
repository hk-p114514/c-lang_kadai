#include "list.h"
#include <stdio.h>

int main() {
	List *head;
	head = getEmptyList();

	printf("================================================================``\n");
	head = createCell((int *)NULL, getEmptyList());

	printf("================================================================``\n");
	printf("%d\n", head->data);
	printf("================================================================``\n");
	printf("%p\n", head->next);

	return (0);
}