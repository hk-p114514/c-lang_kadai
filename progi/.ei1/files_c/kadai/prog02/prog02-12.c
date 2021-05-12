#include <stdio.h>
#include <hamako.h>

main()
{
    int m, n, i, j;
    m = getint("Enter a number 'm' : ");
    n = getint("Enter a number 'n' : ");

    for (i = 0; i < m; i ++) {
        for(j = 0; j < n; j ++) {
            printf("*");
        }
        printf("\n");
    }

    return (0);
}