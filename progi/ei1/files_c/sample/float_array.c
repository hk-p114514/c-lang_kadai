#include <stdio.h>
#include <hamako.h>

main()
{
    int i, n;
    n = getint("How many elements in array do you want to in ? : ");

    float a[n];
    i = 0;
    while(i < n) {
        printf("enter a number of array[%d]", i);
        a[i] = getfloat(" : ");
        i ++;
    }

    i = 0;
    while(i < n) {
        printf("%f\n", a[i]);
        i ++;
    }

    return (0);
}