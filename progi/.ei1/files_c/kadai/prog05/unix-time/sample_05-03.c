#include <stdio.h>
#include <hamako.h>
#include <math.h>

main()
{
    //自然数nの入力
    int n, i;
    n = getint("Enter a number 'n' : ");

    //1を除くn以下の自然数を用意する -> 3 ~ n の奇数
    //3 ~ √n 
    int natural[1000000];
    natural[2] = 1;
    for (i = 3; i <= n; i += 2) {
        if (i == 3 || i == 5 || i == 7) {
            natural[i] = 1;
        }else if ((i % 3 != 0 && i % 5 != 0 && i % 7 != 0)) {
            natural[i] = 1;
        }
    }

    for (i = 2; i <= n; i ++) {
        if (natural[i] == 1) {
            printf("%d\n", i);
        }
    }

    return (0);
}