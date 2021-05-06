#include <stdio.h>
#include <hamako.h>

main()
{
    float x, multiplier;
    int n, i;
    x = getfloat("Enter a number 'x': ");
    n = getint("Enter a number 'n': ");
    multiplier = 1;

    for (i = 0; i < n; i++) {
        multiplier *= x;
    }

    printf("%g^%d = %g\n", x, n, multiplier);

    return (0);
}