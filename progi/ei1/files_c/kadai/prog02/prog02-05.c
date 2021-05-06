#include <stdio.h>
#include <hamako.h>

main()
{
    int n, i, sum;
    n = getint("Enter a number 'n' : ");

    sum = 0;

    for (i = 0; i <= n; i++) {
        sum += i;
    }

    printf("0 ~ %dまでの整数和 = %d\n", n, sum);
    
    return (0);
}