#include <stdio.h>

int main() {
    int n, array[1024], i;
    printf("入力する整数の個数：");
    scanf("%d",&n);

    for (i = 0; i < n; i ++) {
        printf("%d個目の整数：", i + 1);
        scanf("%d",&array[i]);
    }

    printf("\n");

    for (i = 0; i < n; i ++) {
        printf("%d個目の整数：%d\n", i + 1, array[i]);
    }

    return (0);
}