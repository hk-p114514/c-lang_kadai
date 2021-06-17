#include <math.h>
#include <stdio.h>

typedef struct {
	double x; // ｘ座標
	double y; // y座標
} Point;

typedef struct {
	Point p;       // 長方形の左上の点
	double width;  // 長方形の幅
	double height; // 長方形の高さ
} Rect;
/*========================================*/

double ptGetX(Point p);
double ptGetY(Point p);
Point ptCreate(double x, double y);

/*========================================*/

double rctArea(Rect rct);
double rctPerim(Rect rct);
double rctWidth(Rect rct);
double rctHeight(Rect rct);
double rctDiaglen(Rect rct);
Point rctTopLeftCorner(Rect rct);
Rect rctCreate1(Point p1, Point p2);
Rect rctCreate2(Point p, double width, double height);

/*========================================*/

int main() {
	Rect r;
	Point p1, p2;
	double x1, y1, x2, y2, w, h, s;

	printf("長方形１\n");
	printf("対角線の端点1の座標(x, y)：");
	scanf("%lg,%lg", &x1, &y1);
	printf("対角線の端点2の座標(x, y)：");
	scanf("%lg,%lg", &x2, &y2);
	p1 = ptCreate(x1, y1);
	p2 = ptCreate(x2, y2);

	r = rctCreate1(p1, p2); // 長方形の対角線を表す２点で初期化
	putchar('\n');
	// test1
	printf(
	    "左上隅の座標(x, y)：(%g, %g), ",
	    ptGetX(rctTopLeftCorner(r)),
	    ptGetY(rctTopLeftCorner(r)));
	printf("面積：%g, 周囲：%g, 対角線長：%g\n", rctArea(r), rctPerim(r), rctDiaglen(r));
	putchar('\n');

	printf("長方形２\n");
	printf("左上の点の座標(x, y)：");
	scanf("%lg,%lg", &x1, &y1);
	p1 = ptCreate(x1, y1);
	printf("横：");
	scanf("%lg", &w);
	printf("縦：");
	scanf("%lg", &h);

	r = rctCreate2(p1, w, h); // 長方形の左上の点と、幅および高さで初期化
	putchar('\n');
	printf(
	    "左上隅の座標(x, y)：(%g, %g), ",
	    ptGetX(rctTopLeftCorner(r)),
	    ptGetY(rctTopLeftCorner(r)));
	printf("面積：%g, 周囲：%g, 対角線長：%g\n", rctArea(r), rctPerim(r), rctDiaglen(r));

	return (0);
}
// end main
/*========================================
    変更した関数 {
        rctHeight(),
        rctWidth(),
        rctCreate1(),
        rctCreate2(),
    }
========================================*/

/**********************************/
// - Point型の操作関数
/**********************************/

/* ptGetX()
    概要:点ｐのx座標を返す
*/
// 第一引数: ｘ座標を求めたいPoint型の値
// 返り値  : 求めたx座標
double ptGetX(Point p) {
	return (p.x);
}

/*========================================*/

/* ptGetY()
    概要:点ｐのy座標を返す
*/
// 第一引数: y座標を求めたいPoint型の値
// 返り値  : 求めたy座標
double ptGetY(Point p) {
	return (p.y);
}

/*========================================*/

/* ptCreate()
    概要:座標(x, y)の点を生成する
*/
// 第一引数: 作りたい点pのx座標
// 第一引数: 作りたい点pのy座標
// 返り値  : 生成したPoint型の値
Point ptCreate(double x, double y) {
	Point point;
	point.x = x;
	point.y = y;

	return (point);
}

/**********************************/
// - Rect型の操作関数
/**********************************/

/* rctArea()
    概要:長方形rctの面積を返す
*/
// 第一引数: 面積を求めたいRect型の値
// 返り値  : 求めた面積
double rctArea(Rect rct) {
	double height = rctHeight(rct);
	double width = rctWidth(rct);
	return (height * width);
}

/*========================================*/

/* rctPerim()
    概要:長方形rctの周囲の長さを返す
*/
// 第一引数: 周囲の長さを求めたいRect型の値
// 返り値  : もとめた周囲の長さ
double rctPerim(Rect rct) {
	double height = rctHeight(rct);
	double width = rctWidth(rct);

	return ((height * 2) + (width * 2));
}

/*========================================*/

/* rctWidth()
    概要:長方形rctの幅（横）の長さを返す
*/
// 第一引数: 幅を求めたいRect型の値
// 返り値  : 求めた幅
double rctWidth(Rect rct) {
	return (rct.width);
}

/*========================================*/

/* rctHeight()
    概要:長方形rctの高さ（縦）の長さを返す
*/
// 第一引数: 高さを求めたいRect型の値
// 返り値  : 求めた高さ
double rctHeight(Rect rct) {
	return (rct.height);
}

/*========================================*/

/* rctTopLeftCorner()
    概要:長方形rctの左上隅の点を返す
*/
// 第一引数: 左上隅の点を取得したい長方形Rect型の値
// 返り値  : 調べた左上隅の点
Point rctTopLeftCorner(Rect rct) {
	return (rct.p);
}

/*========================================*/

/* rctCreate1()
    概要:対角線を表す2点p1,p2から、長方形を生成する
*/
// 第1数: 対角線を表す点
// 第2引数: 対角線を表す点
// 返り値  : 生成したRect型の長方形
Rect rctCreate1(Point p1, Point p2) {
	Rect create;
	Point leftTop;
	Point rightBottom;
	double width, height;

	if (ptGetX(p1) < ptGetX(p2)) {
		leftTop = p1;
	} else {
		leftTop = p2;
	}

	height = fabs(ptGetY(p1) - ptGetY(p2));
	width = fabs(ptGetX(p1) - ptGetX(p2));

	create.p = leftTop;
	create.width = width;
	create.height = height;

	return (create);
}

/*========================================*/

/* rctCreate2()
    概要:左上の1点pと、幅 width及び高さ height の長さから、長方形を生成する
*/
// 第1引数: 左上の点p
// 第2引数: 横幅
// 第3引数: 高さ
// 返り値  : 生成した長方形
Rect rctCreate2(Point p, double width, double height) {
	Rect create;
	create.p = p;
	create.width = width;
	create.height = height;

	return (create);
}

/*========================================*/

/* rctDialoglen()
    概要:長方形rctの対角線の長さを返す
*/
// 第1引数: 対角線の長さを求めたいRect型の値
// 返り値  : 求めた対角線の長さ
double rctDiaglen(Rect rct) {
	Point topLeft = rctTopLeftCorner(rct);
	// 左上隅の点の各座標
	double x1 = ptGetX(topLeft);
	double y1 = ptGetY(topLeft);

	// 右下の点の各座標
	double x2 = x1 + rctWidth(rct);
	double y2 = y1 + rctHeight(rct);

	double x = fabs(x2 - x1);
	double y = fabs(y2 - y1);

	/******************************
	    対角線を求める式は
	    r^2 * x^2 + y^2
	*******************************/

	double diaglen = sqrt(x * x + y * y);

	return (diaglen);
}