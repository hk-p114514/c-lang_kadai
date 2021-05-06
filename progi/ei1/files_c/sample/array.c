#include <stdio.h>
#include <hamako.h>

main()
{
    int n, i;
    n = getint("Enter a number you want elements for array : ");

    int a[n];
    i = 0;
    while(i < n) {
        a[i] = getint("Enter a element for array : ");
        i ++;
    }
}