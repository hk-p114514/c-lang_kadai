#include <stdio.h>
#include <hamako.h>

int chkFizzBuzz(int x, int m, int n);

main() {
    int z, m, n;
    z = getint("Input z: ");
    m = getint("Input m: ");
    n = getint("Input n: ");

    for (int i = -z; i <= z; i ++) {
        printf("%d ", i);
        int checked = chkFizzBuzz(i, m, n);
        if (checked != -1 && checked != 0) {
            if (checked == 3) {
                printf("FizzBuzz");
            } else if (checked == 2) {
                printf("Buzz");
            } else if (checked == 1) {
                printf("Fizz");
            }
        }
        printf("\n");
    }

    return (0);
}

int chkFizzBuzz(int x, int m, int n) {
    // Argument [x, m, n] : 任意の整数
    /* ReturnValue {
        xが0のとき : 0
        xがmのみの倍数のとき : 1
        xがnのみの倍数のとき : 2
        xがmとnの両方の倍数のとき : 3
        xがm,nどちらの倍数でもないとき : -1
    } */
    int ans;
    if (x == 0) {
        // xが0(false)のとき : 戻り値は0
        ans = 0;
    } else if (x % (m * n) == 0) {
        // xがmとnの両方の倍数のとき : 戻り値は3
        ans = 3;
    } else if (x % m == 0) {
        // xがmのみの倍数のとき : 戻り値は1
        ans = 1;
    } else if (x % n == 0) {
        // xがnのみの倍数のとき : 戻り値は2
        ans = 2;
    } else {
        // xがm,nどちらの倍数でもないとき : 戻り値は-1
        ans = -1;
    }

    return (ans);
}
