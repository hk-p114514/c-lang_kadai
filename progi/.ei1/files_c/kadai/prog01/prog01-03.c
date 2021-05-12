#include <stdio.h>
#include <hamako.h>

main()
{
    int a, b, c, max, min, mid;

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
        mid = max;
        max = c;
    } else if (c < min) {
        mid = min;
        min = c;
    } else {
        mid = c;
    }

    printf("max = %d\n", max);
    printf("mid = %d\n", mid);
    printf("min = %d\n", min);

    return (0);
}