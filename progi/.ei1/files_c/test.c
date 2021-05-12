#include <stdio.h>
#include <hamako.h>

main()
{
    int a, b, c, d, max, min;
    a = getint("please enter a number for a : ");
    b = getint("please enter a number for b : ");
    c = getint("please enter a number for c : ");
    d = getint("please enter a number for d : ");

    if(a > b) {
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

    printf("a = %d \n", a);
    printf("b = %d \n", b);
    printf("c = %d \n", c);

    printf("max = %d \n", max);
    printf("min = %d \n", min);

    return (0);
}
