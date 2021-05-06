#include <stdio.h>

int main () {
    int M = -1, N = -1, R, m, n;
    scanf("%d", &m);
    scanf("%d", &n);

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

    printf("%d と %d の 最大公約数　= %d\n", n, m, N);
}