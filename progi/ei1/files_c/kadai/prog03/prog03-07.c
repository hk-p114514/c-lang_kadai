#include <stdio.h>
#include <hamako.h>

main()
{
    int k, len, mv, attention, space;
    char c[1024];
    attention = '~' - ' ' + 1;
    space = ' ';

    len = getstring("Input c : ", c);
    k = getint("Input k : ");
    k %= attention;

    for (int i = 0; i < len; i ++) {
        mv = c[i] + k - space + attention;
        mv %= attention;
        mv += space;
        printf("%c", mv);
    }
    printf("\n");

    return (0);
}