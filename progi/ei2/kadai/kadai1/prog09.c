#include <stdio.h>
#include <hamakou.h>

double sCombResistance(double r1, double r2);

double pCombResistance(double r1, double r2);

main()
{
double r1, r2, r3; // 各抵抗値
    r1 = 15;
    r2 = 20;
    r3 = 35;

    //1. ３つの抵抗の合成抵抗を求める
    //1.1 ２つの並列に繋がれた抵抗の合成抵抗を求める
    double r23; // r2とr3の並列合成抵抗
    r23 = pCombResistance(r2, r3);

    // 確認用出力
    // printf("r2, r3の並列合成抵抗 : %g[Ω]\n", r23);

    //2. r1とr23の直列合成抵抗を求める
    double ans = sCombResistance(r1, r23);

    // 回路の合成抵抗の出力
    printf("回路の合成抵抗 : %lf[Ω]\n", ans);
}

double sCombResistance(double r1, double r2) {
    // Argument [r1, r2] : 抵抗値
    // ReturnValue : r1, r2の直列合成抵抗
    return (r1 + r2);
}

double pCombResistance(double r1, double r2) {
    // Argument [r1, r2] : 抵抗値
    // ReturnValue : r1, r2の並列合成抵抗
    return (1 / (1 / r1 + 1 / r2));
}