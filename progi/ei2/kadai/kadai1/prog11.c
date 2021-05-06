#include <stdio.h>
#include <hamako.h>

int gcm(int m, int n);

main()
{
    int m, n, denominator, numerotor;

    m = getint("分母(m) : ");
    n = getint("分子(n) : ");

    int min, max, getGcm, k, r;

    if (m == 0) {
        printf("Error: 分母が0です\n");
    } else {
        r = n % m;
        if (r == 0) { // 余りが0でないときは整数にして表示
            printf("%d / %d = %d\n", n, m, n / m);
        } else {
            getGcm = gcm(m, n); // gcmが最大公約数
            if (n > m) { // 分母 ＞ 分子のときは帯分数にして表示する
                k = n / m;
                denominator = m / getGcm;
                numerotor = (n % m) / getGcm;
                printf("%d / %d = %d (%d / %d)\n", n, m, k, numerotor, denominator);
            } else {
                // 分子 ＜ 分母のときは既約分数にして表示
                printf("%d / %d = %d / %d\n", n, m, n / getGcm, m / getGcm);
            }
        }
    }

    return (0);
}

int gcm(int n, int m) {
    // Argument [n, m] : 任意の整数
    // ReturnValue : mとnの最大公約数
    int max, min, r;
    // mとnの内、より大きい方をmaxに、より小さい方をminに格納する
    if (m > n) {
        max = m;
        min = n;
    } else {
        max = n;
        min = m;
    }
    
    r = max % min;

    while (r > 0) {
        max = min;
        min = r;
        r = max % min;
    }

    return (min);
}