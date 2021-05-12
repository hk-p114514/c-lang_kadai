#include <stdio.h>
#include <hamako.h>

main()
{
    int n, i, upstairs;
    n = getint("Enter a number 'n' : ");
    upstairs = 1;

    for (i = 1; i <= n; i++) {
        upstairs *= i;
    }

    printf("%d! = %d\n", n, upstairs);
    return (0);
}