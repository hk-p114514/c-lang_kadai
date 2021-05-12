#include <stdio.h>
#include <hamako.h>

main()
{
    int n, i, target, temp;
    n = getint("Enter a number of 'n' : ");

    for (i = 1; i <= n; i ++) {
        printf("%d", i);

        target = i;
        do {
            if (target % 10 == 3 || i % 3 == 0) {
                printf(" アホ");
            }
            temp = target;
            target /= 10;
        } while(target > 0 && temp % 10 != 3 && i % 3 != 0);
        printf("\n");
    }
    return (0);
}