#include <stdio.h>
#include <hamako.h>

main()
{
    int m, n, denominator, numerotor, min, max, gcm, k, r;

    m = getint("分母(m) : ");
    n = getint("分子(n) : ");

    if (m == 0) {
        printf("Error: 分母が0です\n");
    } else {
        r = n % m; // 分子を分母で割った余り
        if (r == 0) { // 余りが0でないときは整数にして表示
            printf("%d / %d = %d\n", n, m, n / m);
        } else { // 余りが０でないときは、帯分数か既約分数にする
            // ここから

            // ユークリッドの互除法で最大公約数を求める
            if (m > n) {
                max = m;
                min = n;
            } else {
                max = n;
                min = m;
            }
            r = max % min;
            while(r > 0) {
                max = min;
                min = r;
                r = max % min;
            }

            // ここまで

            gcm = min; // gcmが最大公約数
            if (n > m) { // 分母 ＞ 分子のときは帯分数にして表示する
                k = n / m;
                denominator = m / gcm;
                numerotor = (n % m) / gcm;
                printf("%d / %d = %d (%d / %d)\n", n, m, k, numerotor, denominator);
            } else {
                // 分子 ＜ 分母のときは既約分数にして表示
                printf("%d / %d = %d / %d\n", n, m, n / gcm, m / gcm);
            }
        }
    }

    return (0);
}