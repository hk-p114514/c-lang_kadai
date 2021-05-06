#include <stdio.h>
#include <hamako.h>

main()
{
    int n, i, sum;
    n = getint("Enter a number of 'n' : ");

    int a[n];
    sum = 0;

    for (i = 0; i < n; i ++) {
        printf("Enter a number of a[%d]", i);
        a[i] = getint(" : ");

        if (a[i] % 2 == 0) {
            sum += a[i];
        }
    }

    printf("偶数のデータの和 = %d\n", sum);

    return (0);
}