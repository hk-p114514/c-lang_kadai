#include <stdio.h>
#include <hamako.h>

main()
{
    int a, b, c, d, max, min;

    a = getint("Input a : ");
    b = getint("Input b : ");
    c = getint("Input c : ");
    d = getint("Input d : ");

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

    if (d > max) {
        max = d;
    } else if (d < min) {
        min = d;
    }

    printf("max = %d\n", max);
    printf("min = %d\n", min);

    return (0);
}