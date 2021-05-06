#include <stdio.h>
#include <hamako.h>

main()
{
    int n, m, i, bg;

    char a[256];
    char b[256];

    n = getstring("Input a : ", a);
    m = getstring("Input b : ", b);

    if (n < m) {
        bg = n;
    } else {
        bg = m;
    }

    i = 0;
    while (i < bg && a[i] == b[i]) {
        i ++;
    }

    printf("%d\n", i);

    return (0);
}
