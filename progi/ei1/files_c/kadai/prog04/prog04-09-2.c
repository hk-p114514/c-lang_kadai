#include <stdio.h>
#include <hamako.h>

main()
{
    int n, i, j, mpos;
    float a[1000], temp;
    //データ数をキーボードから入力
    n = getint("input n : ");
    for (i = 0; i < n ; i ++) {
        printf("Input a[%d]", i);
        a[i] = getfloat(" : ");
    }

    i = 0;
    while(i <= n - 2) {
        // i番目以降の最小値を見つけ、a[i]と入れ替える
        //i番目以降の最小値を見つける

        mpos = i;
        j = i + 1;
        while (j <= n - 1) {
            //a[mpos]とa[j]を比較して必要ならmposを更新する
            if (a[j] < a[mpos]) {
                mpos = j;
            }
            j ++;
        }

        if (a[mpos] != a[i]) {
            //最小値をa[i]と入れ替える
            temp = a[mpos];
            a[mpos] = a[i];
            a[i] = temp;
        }

        i ++;
    }

    //並べ替えたデータを出力
    for (i = 0; i < n; i ++) {
        printf("%g\n", a[i]);
    }

    return (0);

}