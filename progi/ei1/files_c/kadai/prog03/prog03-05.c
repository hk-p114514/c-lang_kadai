#include <stdio.h>
#include <hamako.h>

main()
{
    int n, p;
    p = -1;
    char a[256];
    char c;

    n = getstring("Input a : ", a);
    c = getcharacter("Input c : ");
    
    p = 0;
    while (a[p] != c) {
        p ++;
    }

    if (p > n) {
        p = -1;
    }
    
    printf("%d\n", p);

    return (0);
}
