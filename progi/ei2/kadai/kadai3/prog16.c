#include <stdio.h>
#define MAX_STUDENTS 100   // 生徒の最大人数
#define MAX_NAME_LENGTH 20 // 生徒の名前の最大文字（ヌル文字は含めない）
#define MAX_SCORE 100      // 各科目の満点

int inpuData(int studentNumbers[], char studentNames[][ MAX_NAME_LENGTH + 1 ], int studentScores[]);

int main() {
	// 入力されたデータの個数（人数）
	int n;

	// 各生徒の出席番号
	int studentNumbers[ MAX_STUDENTS ];

	// 各生徒の名前
	char studentNames[ MAX_STUDENTS ][ MAX_NAME_LENGTH + 1 ];

	// 生徒毎の各科目の点数（国語[][0]、数学[][1]、英語[][2]）
	int studentScores[ MAX_STUDENTS ][ 3 ];

	// 1. データの入力
	n = inputData();

	// 2. 試験成績一覧表を表示
	printTable();

	// 3. 度数分布表を表示
	printDegreeDistributionTable();

	return (0);
}

int inputData(int studentNumbers[], char studentNames[][ MAX_NAME_LENGTH + 1 ], int studentScores[]) {
	char buff[ 1024 ];
	// 1. 入力するデータの個数を入力する
	int n;
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d", &n);

	// 2. 各生徒ごとのデータを受け取る
	for (int i = 0; i < n; i++) {
	}
}