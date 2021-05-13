#include <stdio.h>
#define MAX_STUDENTS 100   // 生徒の最大人数
#define MAX_NAME_LENGTH 20 // 生徒の名前の最大文字（ヌル文字は含めない）
#define MAX_SCORE 100      // 各科目の満点

int inputData(int studentNumbers[], char studentLastNames[][ MAX_NAME_LENGTH + 1 ], char studentFirstNames[][ MAX_NAME_LENGTH + 1 ],
              int studentScores[][ 3 ]);

int main() {
	// 入力されたデータの個数（人数）
	int n;

	// 各生徒の出席番号
	int studentNumbers[ MAX_STUDENTS + 1 ];

	// 各生徒の名前
	char studentLastNames[ MAX_STUDENTS + 1 ][ MAX_NAME_LENGTH + 1 ];
	char studentFirstNames[ MAX_STUDENTS + 1 ][ MAX_NAME_LENGTH + 1 ];

	// 生徒毎の各科目の点数（国語[][0]、数学[][1]、英語[][2]）
	int studentScores[ MAX_STUDENTS + 1 ][ 3 ];

	// 1. データの入力
	n = inputData(studentNumbers, studentLastNames, studentFirstNames, studentScores);
	printf("output\n");
	for (int i = 1; i <= n; i++) {
		printf("%d %s %s\n", studentNumbers[ i ], studentLastNames[ i ], studentFirstNames[ i ]);
	}

	// 2. 試験成績一覧表を表示
	// printTable();

	// 3. 度数分布表を表示
	// printDegreeDistributionTable();

	return (0);
}

int inputData(int studentNumbers[], char studentLastNames[][ MAX_NAME_LENGTH + 1 ], char studentFirstNames[][ MAX_NAME_LENGTH + 1 ],
              int studentScores[][ 3 ]) {
	char buff[ 1024 ];
	// 1.
	// 入力するデータの個数を入力する
	int n;
	printf("Input n :");
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d", &n);

	// 2.
	// 各生徒ごとのデータを受け取る
	for (int i = 0; i <= n; i++) {
		int studentNumber;
		int scores[ 3 ];

		printf("出席番号 名字 名前 国語の点数 数学の点数 英語の点数\n");
		fgets(buff, sizeof(buff), stdin);
		sscanf(buff, "%d %s %s %d %d %d", &studentNumber, studentLastNames[ studentNumber ], studentFirstNames[ studentNumber ], &scores[ 0 ],
		       &scores[ 1 ], &scores[ 2 ]);

		studentNumbers[ studentNumber ] = studentNumber;

		for (int j = 0; j < 3; j++) {
			studentScores[ studentNumber ][ j ] = scores[ j ];
		}
	}

	return (n);
}