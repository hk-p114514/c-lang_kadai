#include <stdio.h>

main()
{
    int n;
    printf("enter a number of input : ");
    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i ++) {
        printf("%d\n", i);
    }

    return (0);
}