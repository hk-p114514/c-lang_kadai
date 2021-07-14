// #include <hamakou.h>
#include <math.h>
#include <stdio.h>
#include "complex.h"
#define POW(x) ((x) * (x))
#define MICRO (0.000001)
#define KILO (1000)

double cSize(Complex x_dot);                // 複素数xの大きさ
double phaseAngle(Complex x, int quadrant); // 複素数xの位相角

int main() {
	double L, C, R, f, omega;
	L = 200 * MICRO;
	C = 0.127 * MICRO;
	R = 25;
	f = 100 * KILO;
	// ω = 2πf
	omega = 2 * M_PI * f;

	// 揃っている情報から、xLとxCを求める
	double xL, xC;
	xL = omega * L;
	xC = 1 / (omega * C);

	// R_L及びCの直列インピーダンスを計算する
	Complex inLine_RL, inLine_C;
	inLine_RL = cCreate(R, xL);
	inLine_C = cCreate(0, -xC);

	// 求めたインピーダンスの逆数を求める
	Complex reciprocal_inLine_RL, reciprocal_inLine_C;
	reciprocal_inLine_RL = cDiv(inLine_RL, cMul(inLine_RL, inLine_RL));
	reciprocal_inLine_C = cDiv(inLine_C, cMul(inLine_C, inLine_C));

	// 求めたインピーダンスの逆数を使い、インピーダンスZを求める
	Complex z_dot, numerator, denominator;
	numerator = cCreate(R, xL);
	numerator = cMul(numerator, cCreate(0, -xC));
	denominator = cCreate(R, xL);
	denominator = cAdd(denominator, cCreate(0, -xC));

	z_dot = cDiv(numerator, denominator);
	printf("Z = ");
	cPrint(z_dot);
	printf("[Ω]\n");

	// z_dotの情報からインピーダンスzの大きさを求める
	double z_size;
	z_size = cSize(z_dot);
	printf("Zの大きさ = %g[Ω]\n", z_size);

	// zの位相角を求める
	double theta;
	theta = phaseAngle(z_dot, 1);
	printf("Zの位相角 = %g[rad]\n", theta);

	return (0);
}

/* cSize()
    概要:複素数xの大きさを求める
*/
// 第1引数: Complex型の複素数の値x
// 返り値  : xの大きさ
double cSize(Complex x_dot) {
	// z_dotの情報からインピーダンスzの大きさを求める
	/*========================================
	    z_dot = a + bjのとき、 zの大きさは
	    |z| = √(a^2 + b^2)で求められる
	========================================*/
	double x_size, x_real, x_imag;
	x_real = cReal(x_dot);
	x_imag = cImag(x_dot);
	x_size = sqrt(POW(x_real) + POW(x_imag));

	return (x_size);
}

/* phaseAngle()
    概要:複素数xの位相角を求める
*/
// 第1引数: Complex型の値x
// 第2引数: 求める位相角の象限(1 ~ 4)
// 返り値  : xの位相角
double phaseAngle(Complex x, int quadrant) {
	/*========================================
	    z_dot = |z|∠θ のベクトルを描いたとき、
	    第一象限における位相角は、
	    θ = atan(b / a)で求められる
	========================================*/
	double theta, z_real, z_imag;
	z_real = cReal(x);
	z_imag = cImag(x);

	if (quadrant == 1) {
		theta = atan(z_imag / z_real);
	} else if (quadrant == 2) {
		theta = M_PI - atan(z_imag / z_real);
	} else if (quadrant == 3) {
		theta = atan(z_imag / z_real) - M_PI;
	} else if (quadrant == 4) {
		theta = -atan(z_imag / z_real);
	}

	return (theta);
}