#include <stdio.h>
#include <hamako.h>

main()
{
    int a, b, c, max, min;

    a = getint("Input a : ");
    b = getint("Input b : ");
    c = getint("Input c : ");

    if (a > b) {
        max = a;
        min = b;
    } else {
        max = b;
        min = a;
    }

    if (c > max) {
        max = c;
    } else if (c < min) {
        min = c;
    }

    printf("max = %d\n", max);
    printf("min = %d\n", min);

    return (0);
}