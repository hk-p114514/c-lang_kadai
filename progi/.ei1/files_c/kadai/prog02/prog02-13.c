#include <stdio.h>
#include <hamako.h>

main()
{
    int n, i, j;
    n = getint("Enter a number 'n' : ");

    for (i = 1; i <= n; i ++) {
        for (j = 0; j < i; j ++) {
            printf("*");
        }
        printf("\n");
    }
}