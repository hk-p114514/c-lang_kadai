#include <stdio.h>

extern int data[ 1000 ];

/* sum()
    概要:大域変数data[]の要素の合計値を求める
*/
// 第一引数: 配列の要素数
// 返り値  : 配列の要素の合計値
int sum(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[ i ];
    }

    return (sum);
}