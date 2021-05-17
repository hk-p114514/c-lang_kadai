#include <stdio.h>
#define MAX_STUDENTS 100 // 生徒の最大人数
#define MAX_NAME_LENGTH 20 // 生徒の名前の最大文字（ヌル文字は含めない）
#define MAX_SCORE 100      // 各科目の満点
#define SUBJECTS 3         // 教科の数

void getSum(int n, int studentScores[][ SUBJECTS ], int sum[]);

void getRanking(int n, int sum[], int rank[]);

void sortData(int data[], int n);

void getAvg(int n, int data[], double avg[]);

int getIndex(int n, int array[], int target);

int searchRange(int n, int array[], int min, int max);

int inputData(
    int studentNumbers[],
    char studentLastNames[][ MAX_NAME_LENGTH + 1 ],
    char studentFirstNames[][ MAX_NAME_LENGTH + 1 ],
    int studentScores[][ SUBJECTS ]);

void printTable(
    int n,
    int studentNumbers[],
    char studentLastNames[][ MAX_NAME_LENGTH + 1 ],
    char studentFirstNames[][ MAX_NAME_LENGTH + 1 ],
    int studentScores[][ SUBJECTS ],
    int sum[],
    int rank[],
    double avg[]);

void printDegreeDistributionTable(int n, int sum[]);

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

	// 各生徒の得点の合計値
	int sum[ MAX_STUDENTS + 1 ] = {};

	// 各生徒の得点の平均値
	double avg[ MAX_STUDENTS + 1 ];

	// 各生徒の順位
	int rank[ MAX_STUDENTS + 1 ];

	// 1. データの入力
	n = inputData(studentNumbers, studentLastNames, studentFirstNames, studentScores);

	// 2. 得点の合計を求める
	getSum(n, studentScores, sum);

	// 3. 各生徒の順位を求める
	getRanking(n, sum, rank);

	// 4. 各生徒の得点の平均を求める
	getAvg(n, sum, avg);

	// 5. 試験成績一覧表を表示
	printTable(
	    n,
	    studentNumbers,
	    studentLastNames,
	    studentFirstNames,
	    studentScores,
	    sum,
	    rank,
	    avg);

	// 6. 度数分布表を表示
	printDegreeDistributionTable(n, sum);

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

int inputData(
    int studentNumbers[],
    char studentLastNames[][ MAX_NAME_LENGTH + 1 ],
    char studentFirstNames[][ MAX_NAME_LENGTH + 1 ],
    int studentScores[][ SUBJECTS ]) {
	char buff[ 1024 ];
	// 1.入力するデータの個数を入力する
	int n;
	printf("Input n :");
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d", &n);

	// 2.各生徒ごとのデータを受け取る
	for (int i = 0; i < n; i++) {
		int studentNumber;
		int scores[ SUBJECTS ];
		char lastName[ MAX_NAME_LENGTH + 1 ];
		char firstName[ MAX_NAME_LENGTH + 1 ];

		printf("%d番目の入力\n", i + 1);
		printf("生徒番号 名字 名前 国語の点数 数学の点数 英語の点数\n");
		fgets(buff, sizeof(buff), stdin);
		sscanf(
		    buff,
		    "%d %s %s %d %d %d",
		    &studentNumber,
		    lastName,
		    firstName,
		    &scores[ 0 ],
		    &scores[ 1 ],
		    &scores[ 2 ]);

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
// 第2引数 - 各生徒の3教科の得点の合計
// 第3引数 - 順位を格納する配列
// 戻 り 値 -　なし
void getRanking(int n, int sum[], int rank[]) {
	int sortSum[ MAX_STUDENTS + 1 ];
	for (int i = 1; i <= n; i++) {
		sortSum[ i ] = sum[ i ];
	}

	// 各生徒得点の合計値を大きい順に並べ替えた配列を用意する
	sortData(sortSum, n);

	// 各生徒の順位を求める
	for (int i = 1; i <= n; i++) {
		rank[ i ] = getIndex(n, sortSum, sum[ i ]);
	}

	return;
}

// getAvg()
/* 概要 - 渡されたデータの平均値を求める */
/* 第1引数 - 調べるデータの要素数 */
/* 第2引数 - 生徒ごとの各科目の合計点数 */
/* 第3引数 - 平均値を格納する配列 */
/* 戻り値 - なし */
void getAvg(int n, int data[], double avg[]) {
	for (int i = 1; i <= n; i++) {
		avg[ i ] = (double)data[ i ] / (double)SUBJECTS;
	}

	return;
}

// printTable()
/* 概要 - 各生徒についての成績一覧表を表示する */
/* 第1引数 - 調べるデータの要素数 */
/* 第2引数 - 生徒ごとの各科目の合計点数 */
/* 第3引数 - 平均値を格納する配列 */
/* 戻り値 - なし */
void printTable(
    int n,
    int studentNumbers[],
    char studentLastNames[][ MAX_NAME_LENGTH + 1 ],
    char studentFirstNames[][ MAX_NAME_LENGTH + 1 ],
    int studentScores[][ SUBJECTS ],
    int sum[],
    int rank[],
    double avg[]) {
	// 出力する項目を表示
	printf(
	    "%s %s %-20s\t%3s\t%3s\t%3s\t%3s\t%2s\t%2s\n",
	    "NO "
	    "氏名",
	    "",
	    "",
	    "国語",
	    "数学",
	    "英語",
	    "合計",
	    "順位",
	    "平均");

	putchar('\n');

	// 生徒個人のデータを表示
	for (int i = 1; i <= n; i++) {
		printf(
		    "%2d %s %-20s\t%3d\t%3d\t%3d\t%3d\t%2d\t",
		    i,                       // 生徒番号
		    studentLastNames[ i ],   // 名字
		    studentFirstNames[ i ],  // 名前
		    studentScores[ i ][ 0 ], // 国語の点数
		    studentScores[ i ][ 1 ], // 数学の点数
		    studentScores[ i ][ 2 ], // 英語の点数
		    sum[ i ],                // 合計
		    rank[ i ]                // 順位
		);

		if (avg[ i ] >= 100) {
			printf("%.2lf", avg[ i ]); // 平均
		} else if (avg[ i ] == 0) {
			printf("  %.2lf", avg[ i ]); // 平均
		} else {
			printf(" %.2lf", avg[ i ]); // 平均
		}

		putchar('\n');
	}
	putchar('\n');

	int total[ 4 ] = {}; // 全体の各教科及び合計点数
	// 全体の点数を集計する
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= n; j++) {
			total[ i ] += studentScores[ j ][ i ];
		}
	}

	for (int i = 1; i <= n; i++) {
		total[ 3 ] += sum[ i ];
	}

	// 全体の合計値を表示
	printf(" %20s%s", " ", "合計");
	for (int i = 0; i < SUBJECTS + 1; i++) {
		printf("\t%3d", total[ i ]);
	}
	putchar('\n');

	// 全体の平均値を表示
	printf(" %20s%s", " ", "平均");
	for (int i = 0; i < SUBJECTS + 1; i++) {
		printf("\t%.2lf", (double)total[ i ] / n);
	}
	putchar('\n');

	return;
}

// printDegreeDistributionTable()
/* 概要 -
 * 度数分布表を表示する */
/* 第1引数 - 生徒の人数 */
/* 第2引数 - 合計値の格納された配列 */
/* 戻り値 - なし */
void printDegreeDistributionTable(int n, int sum[]) {
	int min = 0;
	int max = 49;
	int change = 50;
	int maxRange = SUBJECTS * MAX_SCORE;

	for (int i = 0; i <= maxRange / change; i++) {
		int count;

		// 最大値に達した場合、安全のため範囲を最大値のみに絞る
		if (min == maxRange) {
			max = min;
			count = searchRange(n, sum, min, max);
			// 表示しない分を空白で埋める
			printf("%3d - %3s [%2d] ", min, "", count);
		} else {
			count = searchRange(n, sum, min, max);
			printf("%3d - %3d [%2d] ", min, max, count);
		}
		for (int j = 0; j < count; j++) {
			printf("*");
		}
		putchar('\n');
		min += change;
		max += change;
	}

	return;
}

// getIndex()
/* 概要 -
 * 渡されたデータが渡された配列の何番目の要素かを求める */
/* 第1引数 - 調べる配列の要素数 */
/* 第2引数 - 調べる配列 */
/* 第3引数 - 目的のデータ */
/* 戻り値 - データのあった添字 */
int getIndex(int n, int array[], int target) {
	int i = 0;
	while (array[ i ] != target) {
		i++;
	}

	return (i);
}

// sortData()
/* 概要 - 渡されたデータ（配列）を大きい順にソートする */
/* 第1引数 - ソートするデータ（配列） */
/* 第2引数 - ソートするデータの個数 */
/* 戻り値 - なし */
void sortData(int data[], int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (data[ j ] > data[ i ]) {
				int temp = data[ j ];
				data[ j ] = data[ i ];
				data[ i ] = temp;
			}
		}
	}

	return;
}

// searchRange()
/* 概要 - 渡されたデータ（配列）を内に特定の範囲の値がいくつあるか調べる */
/* 第1引数 - ソートするデータ（配列） */
/* 第2引数 - ソートするデータの個数 */
/* 戻り値 - なし */
int searchRange(int n, int array[], int min, int max) {
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (array[ i ] >= min && array[ i ] <= max) {
			count++;
		}
	}

	return (count);
}