#include <stdio.h>
#include <hamako.h>

main()
{
    int n, i;
    n = getint("Enter a number 'n' : ");
    float a[n + 1], x, y, tempX;

    //y = a[n] * x^(n) + a[n - 1] * x^(n - 1) + ... a[1] * x + a[0] の
    //a[n] ~ a[0] を入力
    for (i = 0; i <= n; i ++) {
        printf("Enter a number a[%d]", n - i);
        a[n - i] = getfloat(" : ");
    }

    //xを入力させ、入力されたｘに対応するｙを出力
    do {
        y = 0;
        tempX = 1;
        x = getfloat("Enter a number of 'x' : ");
        //ｘ^(n - i)を取得

        for (i = 0; i <= n; i ++) {
            tempX *= x;
            y += a[i + 1] * tempX;
        }
        y += a[0];

        printf("y = %g\n", y);
    } while (x != 0);

    return (0);
}