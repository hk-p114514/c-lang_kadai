#include <stdio.h>
#include <hamako.h>

main()
{
    int wesCal;
    wesCal = getint("Input year of the Western calendar : ");
    if (wesCal > 0) {
        if (wesCal % 4 != 0) {
            printf("平年です\n");
        } else if (wesCal % 100 != 0) {
            printf("うるう年です\n");
        } else if (wesCal % 400 != 0) {
            printf("平年です\n");
        } else {
            printf("うるう年です\n");
        }
    }
    return (0);
}