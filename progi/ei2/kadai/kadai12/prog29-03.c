#include <stdio.h>

#define W 21
#define H 20

int tileCount(char room[ H ][ W ], int row, int col, int h, int w);

int main() {
	char room[ H ][ W ];
	int h;   // 部屋の行方向のタイルの枚数
	int w;   // 部屋の列方向のタイルの枚数
	int row; // 最初に人が立っている行位置
	int col; // 最初に人が立っている列位置
	int i, j;

	// 部屋の情報を、配列room[]に文字列として読み込む
	scanf("%d%d", &w, &h);
	while (h != 0 && w != 0) {
		for (i = 0; i < h; i++) {
			scanf("%s", room[ i ]);
			for (j = 0; j < w; j++) {
				if (room[ i ][ j ] == '@') {
					row = i; // 最初に人が立っている行位置
					col = j; // 最初に人が立っている列位置
				}
			}
		}
		printf("%d\n", tileCount(room, row, col, h, w));

		scanf("%d%d", &w, &h);
	}

	return (0);
}

int tileCount(char room[ H ][ W ], int row, int col, int h, int w) {
	// 基底条件：もうどこにも行けない -> 0
	char red = '#';
	char floor = '.';
	int count = 1;

	// 上下左右のタイルの位置
	int up = row - 1;
	int down = row + 1;
	int left = col - 1;
	int right = col + 1;

	// 範囲外、もしくはそのマスが赤いタイルのとき、どこにも行けない。-> 0を返す
	if (row < 0 || row >= h || col < 0 || col >= w || room[ row ][ col ] == red) {
		return (0);
	} else {
		// そのマスが赤いタイルでなければ、そのマスを赤いタイルにする -> 重複を回避
		room[ row ][ col ] = red;

		// 現在のマスから上下左右のマスにそれぞれ移動する
		count += tileCount(room, up, col, h, w);    // 上
		count += tileCount(room, down, col, h, w);  // 下
		count += tileCount(room, row, left, h, w);  // 左
		count += tileCount(room, row, right, h, w); // 右
	}

	return (count);
}
