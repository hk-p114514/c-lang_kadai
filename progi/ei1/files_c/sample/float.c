#include <stdio.h>
#include <hamako.h>

main()
{
    float a, b, c, max, min;
    a = getfloat("please enter a number of a : ");
    b = getfloat("please enter a number of b : ");
    c = getfloat("please enter a number of c : ");

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

    printf("a = %f \n", a);
    printf("b = %f \n", b);
    printf("c = %f \n", c);

    printf("max = %f \n", max);
    printf("min = %f \n", min);

    return (0);
}
