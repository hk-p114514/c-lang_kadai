#include <stdio.h>
#include <hamako.h>
#include <string.h>

main()
{
    int n, len, p, i;
    char c[256];
    len= getstring("Input c : ", c);
    p = 1;
    for (i = 0; i < len/ 2; i ++) {
        if (c[i] != c[len- i - 1]) {
            p = 0;
        }
    }

    printf("p = %d\n", p);

    return (0);
}