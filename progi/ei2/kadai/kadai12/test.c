#include <stdio.h>
#define MAP_SIZE 25

int countPath(int x, int y);

int map[ MAP_SIZE ][ MAP_SIZE ] = {{0}}; // この配列で、各交差点を通る道筋の総数をメモしておく

int main(void) {
	int a, b, n, x, y, i;

	scanf("%d %d", &a, &b); // 南北方向の道路の本数，東西方向の道路の本数を入力
	scanf("%d", &n);        // 工事中の交差点の数を入力

	for (i = 0; i < n; i++) {
		scanf("%d %d", &x, &y); // n個の工事中の交差点の位置を入力し、
		map[ x ][ y ] = -1;     // 通行できないことを-1で表す
	}
	printf("%d\n", countPath(a, b));

	return (0);
}

/*
[1,1]にある家から[x,y]の学校に向かう、
通学可能な道路の総数をメモ化再帰で求める
*/
int countPath(int x, int y) {
	/*基底条件
	[x,y]が通行止めのとき -> 通れない 0
	[x,y]が[1,1]のとき  -> 通学可能 1
	*/
	int count = 0;  // 通学可能な通学路の個数
	int xi = x - 1; // xを配列の添字に変換
	int yi = y - 1; // yを配列の添字に変換

	// [x,y]が範囲外のとき、もしくは[x,y]が通行止めのとき、0を返す
	if (xi < 0 || yi < 0 || xi >= MAP_SIZE || yi >= MAP_SIZE || map[ x ][ y ] == -1) {
		return (0);
	}

	// [x,y]が[1,1]のとき、1を返す
	if (x == 1 && y == 1) {
		return (1);
	}

	// [x,y]から南、西に行くときの座標
	int west = x - 1;
	int south = y - 1;

	// [x,y]から南、西に行く
	count += countPath(x, south);
	count += countPath(west, y);

	return (count);
}