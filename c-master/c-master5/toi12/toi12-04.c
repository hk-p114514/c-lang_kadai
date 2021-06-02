#include <stdio.h>
double FindDiscriminantFormula(double a, double b, double c);

int main() {
	double a, b, c, d;
	char buff[ 256 ];

	printf("a b c: ");
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%lf %lf %lf", &a, &b, &c);

	d = FindDiscriminantFormula(a, b, c);
	if (d > 0) {
		printf("D = %g: 解2個\n", d);
	} else if (d < 0) {
		printf("D = %g: 解なし\n", d);
	} else {
		printf("D = %g: 重解\n", d);
	}

	return (0);
}

/*
    FindDiscriminantFormula()
    概要：引数a, b, cを２次方程式 ax^2 + bx + c = 0の
    係数としたときの、判別式 FindDiscriminantFormula = b^2 - 4ac を求める
*/
// 第1引数：２次方程式 ax^2 + bx + c = 0 の a に該当する値
// 第2引数：２次方程式 ax^2 + bx + c = 0 の b に該当する値
// 第3引数：２次方程式 ax^2 + bx + c = 0 の c に該当する値
// 返り値：判別式 D = b^2 - 4ac の計算結果
double FindDiscriminantFormula(double a, double b, double c) {
	return ((b * b) - 4 * a * c);
}