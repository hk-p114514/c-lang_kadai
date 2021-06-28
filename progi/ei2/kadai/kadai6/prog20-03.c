// #include <hamakou.h>
#include <math.h>
#include <stdio.h>
#define POW(x) ((x) * (x))
#define MICRO (0.000001)
#define KILO (1000)

// Complex型の定義
typedef struct {
	double real; // 実数部
	double imag; // 虚数部
} Complex;

// 抽象データ型として扱うために必要になる関数群
Complex cAdd(Complex x, Complex y);         // x + y
Complex cSub(Complex x, Complex y);         // x - y
Complex cMul(Complex x, Complex y);         // x * y
Complex cDiv(Complex x, Complex y);         // x / y
void cPrint(Complex x);                     // 複素数の表示
Complex cCreate(double a, double b);        // a + bj の設定
double cSize(Complex x_dot);                // 複素数xの大きさ
double phaseAngle(Complex x, int quadrant); // 複素数xの位相角
double cReal(Complex x);                    // 実数部の取得
double cImag(Complex x);                    // 虚数部の取得

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

/* cAdd()
    概要:x = a + bj, y = c + djの時、x + y を計算する
*/
// 第1引数: 計算する複素数a + bj
// 第2引数: 計算する複素数c + dj
// 返り値  : 計算した x + y
Complex cAdd(Complex x, Complex y) {
	Complex added;
	double real, imag;

	real = cReal(x) + cReal(y);
	imag = cImag(x) + cImag(y);

	added = cCreate(real, imag);

	return (added);
}

/* cSub()
    概要:x = a + bj, y = c + djの時、x - y を計算する
*/
// 第1引数: 計算する複素数a + bj
// 第2引数: 計算する複素数c + dj
// 返り値  : 計算した x - y
Complex cSub(Complex x, Complex y) {
	double b, d;
	// 引き算はマイナスの足し算なのでcAdd()が使える
	b = cReal(y);
	d = cImag(y);

	// yの各符号を反転する
	b = -b;
	d = -d;

	// 符号を反転した値で足し算を行う
	Complex substracted;
	substracted = cAdd(x, cCreate(b, d));

	return (substracted);
}

/* cMul()
    概要:x = a + bj, y = c + djの時、x * y を計算する
*/
// 第1引数: 計算する複素数a + bj
// 第2引数: 計算する複素数c + dj
// 返り値  : 計算した x * y
Complex cMul(Complex x, Complex y) {
	double a, b, c, d;
	a = cReal(x);
	b = cImag(x);
	c = cReal(y);
	d = cImag(y);

	Complex multiplied;

	double real, imag;
	real = (a * c) - (b * d);
	imag = (a * d) + (b * c);

	multiplied = cCreate(real, imag);

	return (multiplied);
}

/* cDiv()
   概要:x = a + bj, y = c + djの時、x / y を計算する
*/
// 第1引数: 計算する複素数a + bj
// 第2引数: 計算する複素数c + dj
// 返り値  : 計算した x / y
Complex cDiv(Complex x, Complex y) {
	double a, b, c, d;
	a = cReal(x);
	b = cImag(x);
	c = cReal(y);
	d = cImag(y);

	double realNumerator, imagNumerator, denominator;
	denominator = POW(c) + POW(d);
	realNumerator = a * c + b * d;
	imagNumerator = b * c - a * d;

	Complex isDivision;
	double real, imag;
	real = realNumerator / denominator;
	imag = imagNumerator / denominator;

	isDivision = cCreate(real, imag);

	return (isDivision);
}

/* cCreate()
    概要:実数a, bから複素数a + bjを初期化（生成）する
*/
// 第1引数 : 複素数a + bjの実数部a
// 第2引数 : 複素数a + bjの虚数部b
// 返り値  : 生成した複素数a + bj
Complex cCreate(double a, double b) {
	Complex create;
	create.real = a;
	create.imag = b;

	return (create);
}

/* cPrint()
    概要:複素数xをa + bjのように表示する
*/
// 第1引数: 表示したい複素数x
// 返り値  : なし
void cPrint(Complex x) {
	double real, imag;
	real = cReal(x);
	imag = cImag(x);

	if (imag == 0) {
		printf("%g", real);
	} else if (imag < 0) {
		imag = -imag;
		printf("%g - %gj", real, imag);
	} else {
		printf("%g + %gj", real, imag);
	}

	return;
}

/* cReal()
    概要:x = a + bjから、実数部aを取り出す
*/
// 第1引数: 複素数x
// 返り値  : xの実数部a
double cReal(Complex x) {
	return (x.real);
}

/* cImag()
    概要:x = a + bjから、虚数部bを取り出す
*/
// 第1引数: 複素数x
// 返り値  : xの虚数部b
double cImag(Complex x) {
	return (x.imag);
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
// 第2引数: 求める位相角の象限
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
	}

	return (theta);
}