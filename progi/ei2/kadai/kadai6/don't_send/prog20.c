#include <hamakou.h>
#include <stdio.h>

// Complex型の定義
typedef struct {
	double real; // 実数部
	double imag; // 虚数部
} Complex;

// 抽象データ型として扱うために必要になる関数群
Complex cAdd(Complex x, Complex y);  // x + y
Complex cSub(Complex x, Complex y);  // x - y
Complex cMul(Complex x, Complex y);  // x * y
Complex cDiv(Complex x, Complex y);  // x / y
void cPrint(Complex x);              // 複素数の表示
Complex cCreate(double a, double b); // a + bj の設定
double cReal(Complex x);             // 実数部の取得
double cImag(Complex x);             // 虚数部の取得

int main() {
	Complex x, y, z;
	double a, b;

	printf("x <- 実数部 虚数部："); // 実数部と虚数部の入力
	scanf("%lg %lg", &a, &b);
	x = cCreate(a, b); // 複素数ｘの初期化

	printf("y <- 実数部 虚数部："); // 実数部と虚数部の入力
	scanf("%lg %lg", &a, &b);
	y = cCreate(a, b); // 複素数ｙの初期化

	putchar('\n');
	printf("複素数 x = ");
	cPrint(x);
	putchar('\n');
	printf("複素数 y = ");
	cPrint(y);
	putchar('\n');
	printf("の四則演算\n");

	z = cAdd(x, y); // 加算
	printf("x + y = ");
	cPrint(z);
	putchar('\n');
	z = cSub(x, y); // 減算
	printf("x - y = ");
	cPrint(z);
	putchar('\n');
	z = cMul(x, y); // 乗算
	printf("x * y = ");
	cPrint(z);
	putchar('\n');
	z = cDiv(x, y); // 徐算
	printf("x / y = ");
	cPrint(z);
	putchar('\n');

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
	// 引き算はマイナスの足し算なのでcAdd()が使える
}

/* cMul()
    概要:x = a + bj, y = c + djの時、x * y を計算する
*/
// 第1引数: 計算する複素数a + bj
// 第2引数: 計算する複素数c + dj
// 返り値  : 計算した x * y
Complex cMul(Complex x, Complex y) {
}

/* cDiv()
   概要:x = a + bj, y = c + djの時、x / y を計算する
*/
// 第1引数: 計算する複素数a + bj
// 第2引数: 計算する複素数c + dj
// 返り値  : 計算した x / y
Complex cDiv(Complex x, Complex y) {
}

/* cCreate()
    概要:実数a, bから複素数a + bjを初期化（生成）する
*/
// 第1引数 : 複素数a + bjの実数部a
// 第2引数 : 複素数a + bjの虚数部b
// 返り値  : 生成した複素数a + bj
Complex cCreate(double a, double b) {
}

/* cPrint()
    概要:複素数xをa + bjのように表示する
*/
// 第1引数: 表示したい複素数x
// 返り値  : なし
void cPrint(Complex x) {
}

/* cReal()
    概要:x = a + bjから、実数部aを取り出す
*/
// 第1引数: 複素数x
// 返り値  : xの実数部a
double cReal(Complex x) {
}

/* cImag()
    概要:x = a + bjから、虚数部bを取り出す
*/
// 第1引数: 複素数x
// 返り値  : xの虚数部b
double cImag(Complex x) {
}
