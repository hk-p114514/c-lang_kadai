#include <stdio.h>

main()
{
    int n, m;
    printf("Input a number 'n' : ");
    scanf("%d", &n);
    printf("Input a number 'm' : ");
    scanf("%d", &m);

    printf("%d / %d = %d 余り %d\n", n, m, n / m, n % m);

    return (0);
}