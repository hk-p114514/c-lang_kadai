#include <stdio.h>
#include <hamako.h>

main()
{
    int n, i, mark, upper, lower, number;
    mark   = 0;
    upper  = 0;
    lower  = 0;
    number = 0;

    char c[256];
    n = getstring("Input c : ", c);

    for (i = 0; i < n; i ++) {
        int c_num = (int)c[i];
        if (c_num >= '0' && c_num <= '9') {
            number ++;
        } else if (c_num >= 'A' && c_num <= 'Z') {
            upper ++;
        } else if (c_num >= 'a' && c_num <= 'z') {
            lower ++;
        } else if (!(c_num < ' ' || c_num > '~')){
            mark ++;
        }
    }

    printf("英大文字の数 = %d\n", upper);
    printf("英小文字の数 = %d\n", lower);
    printf("記号の数 =     %d\n", mark);
    printf("数字の数 =     %d\n", number);

    return (0);
}