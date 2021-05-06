#include <stdio.h>
#include <hamako.h>

main()
{
    int n, m, result, remainder, M, N, R;

    //整数ｎ、ｍを入力する
    n = getint("Input n : ");
    m = getint("Input m : ");

    // n / m の余りを求める
    remainder = n % m;

    
    if (remainder == 0) {// n / m の余りが０ => n / m の計算結果が整数ならば n / m の計算結果を表示する
        // 計算結果を表示する
        printf("%d / %d = %d\n", n, m, n / m);
    } else {
        // n / m　の余りが０ではなかったら n / m の結果と n, m の最大公約数を見つける

        // n / m を計算する
        result = n / m;

        // n と m の最大公約数を見つける
        if (m > n) {
            M = m;
            N = n;
        } else {
            M = n;
            N = m;
        }
        R = M % N;
        while (R != 0) {
            M = N;
            N = R;
            R = M % N;
        }

    }

    return (0);
}