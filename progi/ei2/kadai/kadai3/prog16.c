#include <stdio.h>
#define MAX_STUDENTS 100   // 生徒の最大人数
#define MAX_NAME_LENGTH 20 // 生徒の名前の最大文字（ヌル文字は含めない）
#define MAX_SCORE 100      // 各科目の満点
#define SUBJECTS 3         // 教科の数

int inputData(int studentNumbers[], char studentLastNames[][ MAX_NAME_LENGTH + 1 ],
              char studentFirstNames[][ MAX_NAME_LENGTH + 1 ], int studentScores[][ SUBJECTS ]);
void getSum(int n, int studentScores[][ SUBJECTS ], int sum[]);
void getRanking(int n, int studentScores[][ SUBJECTS ], int rank[]);
void sortData(int data[], int n);
int getIndex(int n, int array[], int target);

int main() {
	// 入力されたデータの個数（人数）
	int n;

	// 各生徒の生徒番号
	int studentNumbers[ MAX_STUDENTS + 1 ];

	// 各生徒の名前
	char studentLastNames[ MAX_STUDENTS + 1 ][ MAX_NAME_LENGTH + 1 ];
	char studentFirstNames[ MAX_STUDENTS + 1 ][ MAX_NAME_LENGTH + 1 ];

	// 生徒毎の各科目の点数（国語[][0]、数学[][1]、英語[][2]）
	int studentScores[ MAX_STUDENTS + 1 ][ SUBJECTS ];

	// 1. データの入力
	n = inputData(studentNumbers, studentLastNames, studentFirstNames, studentScores);

	// 2. 得点の合計を求める
	int sum[ MAX_STUDENTS + 1 ] = {}; // 各生徒の合計値

	getSum(n, studentScores, sum);

	// 3. 各生徒の順位を求める
	int rank[ MAX_STUDENTS + 1 ];
	getRanking(n, studentScores, rank);
	// 4. 各生徒の得点の平均を求める

	// 5. 試験成績一覧表を表示
	// printTable();

	// 6. 度数分布表を表示
	// printDegreeDistributionTable();

	return (0);
}

// inputData()
/*
    - 概要 -
    入力されるn人の生徒の各データを入力する
*/
// 第1引数 - 生徒の生徒番号
// 第2引数 - 各生徒の名字
// 第3引数 - 各生徒の名前
// 第4引数 - 各生徒の国語、数学、英語の点数
/* 戻り値　 - 生徒の人数 n */
int inputData(int studentNumbers[], char studentLastNames[][ MAX_NAME_LENGTH + 1 ],
              char studentFirstNames[][ MAX_NAME_LENGTH + 1 ], int studentScores[][ SUBJECTS ]) {
	char buff[ 1024 ];
	// 1.
	// 入力するデータの個数を入力する
	int n;
	printf("Input n :");
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d", &n);

	// 2.
	// 各生徒ごとのデータを受け取る
	for (int i = 0; i < n; i++) {
		int studentNumber;
		int scores[ SUBJECTS ];
		char lastName[ MAX_NAME_LENGTH + 1 ];
		char firstName[ MAX_NAME_LENGTH + 1 ];

		printf("%d番目の入力\n", i);
		printf("生徒番号 名字 名前 国語の点数 数学の点数 英語の点数\n");
		fgets(buff, sizeof(buff), stdin);
		sscanf(buff, "%d %s %s %d %d %d", &studentNumber, lastName, firstName, &scores[ 0 ], &scores[ 1 ], &scores[ 2 ]);

		studentNumbers[ studentNumber ] = studentNumber;

		sscanf(lastName, "%s", studentLastNames[ studentNumber ]);
		sscanf(firstName, "%s", studentFirstNames[ studentNumber ]);

		for (int j = 0; j < SUBJECTS; j++) {
			studentScores[ studentNumber ][ j ] = scores[ j ];
		}
	}

	return (n);
}

// getSum()
/*
    - 概要 -
    渡された各生徒の3教科の得点の合計を求める
*/
// 第1引数 - 求める合計値の個数（生徒の人数）
// 第2引数 - 各生徒の3教科の得点
// 第3引数 - 各生徒の得点の合計値を格納する配列
void getSum(int n, int studentScores[][ SUBJECTS ], int sum[]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < SUBJECTS; j++) {
			sum[ i ] += studentScores[ i ][ j ];
		}
	}
}

// getRanking()
/*
    - 概要 -
    各生徒の得点の順位を求める
*/
// 第1引数 - 求める合計値の個数（生徒の人数）
// 第2引数 - 各生徒の3教科の得点
// 第3引数 - 順位を格納する配列
// 戻 り 値 -　なし
void getRanking(int n, int studentScores[][ SUBJECTS ], int rank[]) {
	int sortedStudentScores[ MAX_STUDENTS + 1 ][ SUBJECTS ];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < SUBJECTS; j++) {
			sortedStudentScores[ i ][ j ] = studentScores[ i ][ j ];
		}
	}
	// 大きい順にソートしたデータを作成
	sortData(sortedStudentScores, n);

	// 各生徒の順位を求める
	for (int i = 1; i <= n; i++) {
		rank[ i ] = getIndex(n, sortedStudentScores, studentScores[ i ]);
	}
}

// getIndex()
/* 概要 - 渡されたデータが渡された配列の何番目の要素かを求める */
/* 第1引数 - 調べる配列の要素数 */
/* 第2引数 - 調べる配列 */
/* 第3引数 - 目的のデータ */
/* 戻り値 - データのあった添字 */
int getIndex(int n, int array[], int target) {
	int ans;
	for (int i = 1; i <= n; i++) {
		if (array[ i ] == target) {
			ans = i;
			break;
		}
	}
	return (ans);
}

// sortData()
/* 概要 - 渡されたデータ（配列）を大きい順にソートする */
/* 第1引数 - ソートするデータ（配列） */
/* 第2引数 - ソートするデータの個数 */
/* 戻り値 - なし */
void sortData(int data[], int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (data[ j ] > data[ i ]) {
				int temp = data[ j ];
				data[ j ] = data[ i ];
				data[ i ] = temp;
			}
		}
	}

	return;
}