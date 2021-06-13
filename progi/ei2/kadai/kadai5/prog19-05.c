#include <stdio.h>

typedef struct {
	double x; // ｘ座標
	double y; // y座標
} Point;

typedef struct {
	Point p1; // 対角線の端点1
	Point p2; // 対角線の端点2
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
Point rctTopLeftCorner(Rect rct);
Point rctPoint1(Rect rct);
Point rctPoint2(Rect rct);
Rect rctCreate1(Point p1, Point p2);
Rect rctCreate2(Point p, double width, double height);

/*========================================*/

int main() {

	return (0);
}

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

/*========================================*/

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
	double width = ptGetX(rctPoint1(rct)) - ptGetX(rctPoint2(rct));
	if (width < 0) {
		width = -width;
	}

	return (width);
}

/*========================================*/

/* rctHeight()
    概要:長方形rctの高さ（縦）の長さを返す
*/
// 第一引数: 高さを求めたいRect型の値
// 返り値  : 求めた高さ
double rctHeight(Rect rct) {
	double height = ptGetX(rctPoint1(rct)) - ptGetX(rctPoint2(rct));
	if (height < 0) {
		height = -height;
	}

	return (height);
}

/*========================================*/

/* rctTopLeftCorner()
    概要:長方形rctの左上隅の点を返す
*/
// 第一引数: 左上隅の点を取得したい長方形Rect型の値
// 返り値  : 調べた左上隅の点
Point rctTopLeftCorner(Rect rct) {
	double x1, x2, y1, y2;
	x1 = ptGetX(rctPoint1(rct));
	x2 = ptGetX(rctPoint2(rct));

	y1 = ptGetY(rctPoint1(rct));
	y2 = ptGetY(rctPoint2(rct));
	double top, left;

	if (x1 < x2) {
		left = x1;
	} else {
		left = x2;
	}
}

/*========================================*/

/* rctPoint1()
    概要:長方形rctの対角線の端点の内1つ目を返す
*/
// 第一引数: Rect型の長方形の値
// 返り値  : 求めたPoint型の値
Point rctPoint1(Rect rct) {
	return (rct.p1);
}

/*========================================*/

/* rctPoint2()
    概要:長方形rctの対角線の端点の内2つ目を返す
*/
// 第一引数: Rect型の長方形の値
// 返り値  : 求めたPoint型の値
Point rctPoint2(Rect rct) {
	return (rct.p2);
}