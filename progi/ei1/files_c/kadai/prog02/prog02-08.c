#include <stdio.h>
#include <hamako.h>

main()
{
    int m, n, cnt3, cnt5, cnt35, i;
    i = 0;
    cnt3 = 0;
    cnt5 = 0;
    cnt35 = 0;

    m = getint("Enter a number 'm' : ");
    n = getint("Enter a number 'n' : ");

    for (i = m; i <= n; i++) {
        if (i != 0) {
            if (i % 15 == 0) {
                cnt3 ++;
                cnt5 ++;
                cnt35 ++;
            } else if (i % 3 == 0) {
                cnt3 ++;
            } else if (i % 5 == 0) {
                cnt5 ++;
            }
        } 
    }

    printf("3の倍数 : %d\n", cnt3);
    printf("5の倍数 : %d\n", cnt5);
    printf("3と5の公倍数 : %d\n", cnt35);

    return (0);
}