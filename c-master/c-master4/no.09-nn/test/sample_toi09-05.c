#include <stdio.h>
#include <hamako.h>

int main() {
    int n;

    // 入力する文字列の個数
    n = getint("入力する文字列の個数 : ");

    int len;
    char str[1024][256];
    char temp;

    for (int i = 0; i < n; i ++) {
        // 文字列の入力
        printf("文字列_%d", i + 1);
        len = getstring(":", str[i]);

        // 文字列を逆順にする
        for (int j = 0; j < len; j ++, len --) {
            temp = str[i][j];
            str[i][j] = str[i][len - 1];
            str[i][len - 1] = temp;
        }
    }

    for (int i = 0; i < n; i ++) {
        printf("文字列%dの逆順 : %s\n", i + 1, str[i]);
    }

    return (0);
}