#include <stdio.h>
#include <hamako.h>

main()
{
    int n, i, odd, even;
    even = 0;
    odd = 0;
    n = getint("Enter a number 'n' : ");

    for (i = 1; i <= n; i += 2) {
        odd += i;
    }

    for (i = 2; i <= n; i += 2) {
        even += i;
    }

    printf("偶数の和 = %d\n", even);
    printf("奇数の和 = %d\n", odd);
    
    return (0);
}