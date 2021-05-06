#include <stdio.h>
#include <hamako.h>

main()
{
    int a, b, c, max, min;
    a = getint("please enter a number of a : ");
    b = getint("please enter a number of b : ");
    c = getint("please enter a number of c : ");

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
