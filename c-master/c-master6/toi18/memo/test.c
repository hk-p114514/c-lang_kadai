#include <stdio.h>

int main() {
	int i, j;
	int *p, *q;

	p = &i;

	p = &*&i;

	// i = (int)p;

	// q = &p;

	// *p = &j;

	// i = (*&)j;

	i = *&*&j;

	i = *p++ + *q;

	return (0);
}