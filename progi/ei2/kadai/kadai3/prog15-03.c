#include <stdio.h>
int inputData(double data[]);
double sumData(int n, double data[]);
double findVariance(double data[], double avg, int n);
void sortData(double data[], int n);
void printNumbers(double data[], int n);
void printData(double max, double min, double sum, double avg, double variance);

int main() {
	int n;               // データ数
	double data[ 1024 ]; // データ

	// 1. n個の実数を入力する
	n = inputData(data);

	// // 2. 合計を求める
	double sum = 0; // 合計
	sum = sumData(n, data);

	// 3. 平均を求める
	double avg; // データの平均
	avg = sum / n;

	// // 4. 分散を求める
	double variance; // 分散
	variance = findVariance(data, avg, n);

	// 5. 大きい順に並べ替える
	sortData(data, n);

	// // 6. 最大値と最小値を求める
	double max, min;
	max = data[ 0 ];
	min = data[ n - 1 ];

	// // 7. n個の実数を表示する
	printNumbers(data, n);

	putchar('\n'); // 見やすくするための改行

	// // 8. 最大値、最小値、合計、平均、分散を表示する
	printData(max, min, sum, avg, variance);
	return (0);
}

// inputData()
/* 概要 : 渡された配列にデータを格納し、また入力されたデータ数を返す */
/* 第一引数 - データを格納する配列 */
/* 戻り値 	- 入力したデータの個数 */
int inputData(double data[]) {
	int n; // 入力するデータ数
	char buf[ 1024 ];

	printf("入力するデータ数 :");
	fgets(buf, sizeof(buf), stdin);
	sscanf(buf, "%d", &n);

	for (int i = 0; i < n; i++) {
		printf("%d番目のデータ :", i + 1);
		fgets(buf, sizeof(buf), stdin);
		sscanf(buf, "%lf", &data[ i ]);
	}

	return (n);
};

// sumData()
/* 概要 : 渡された配列の値を合計する */
/* 第1引数	- 合計を求めるデータの個数（配列の要素数） */
/* 第2引数	- 合計を求めるデータの格納された配列 */
/* 戻り値	- 配列に格納された倍精度実数の合計値 */
double sumData(int n, double data[]) {
	double sum = 0;

	for (int i = 0; i < n; i++) {
		sum += data[ i ];
	}
	return (sum);
}

// findVariance()
/* 概要 :  渡されたデータ（配列）の標本分散を求める */
/* 第1引数	- 標本分散を求めるデータ（配列） */
/* 第2引数	- 標本分散を求めるデータの平均値 */
/* 第3引数	- 標本分散を求めるデータの個数 */
/* 戻り値	- 渡されたデータ（配列）の標本分散 */
double findVariance(double data[], double avg, int n) {
	double variance = 0;

	for (int i = 0; i < n; i++) {
		variance += (data[ i ] - avg) * (data[ i ] - avg);
	}

	variance /= n;

	return (variance);
}

// sortData()
/* 概要 - 渡されたデータ（配列）を大きい順にソートする */
/* 第1引数 - ソートするデータ（配列） */
/* 第2引数 - ソートするデータの個数 */
/* 戻り値 - なし */
void sortData(double data[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (data[ j ] > data[ i ]) {
				double temp = data[ j ];
				data[ j ] = data[ i ];
				data[ i ] = temp;
			}
		}
	}

	return;
}

// printNumbers
/* 概要 - 渡されたｎ個のデータ（配列）を表示する */
/* 第1引数 - 表示するデータ（配列）  */
/* 第2引数 - 表示するデータの個数 */
void printNumbers(double data[], int n) {
	for (int i = 0; i < n; i++) {
		printf("x[ %d]: %g\n", i, data[ i ]);
	}

	return;
}

// printData
/* 概要 - データ {
    集計した最大値、最小値、合計、平均、分散
}
    を表示する */
/* 第1引数 - 最大値 */
/* 第2引数 - 最小値 */
/* 第3引数 - 合計 */
/* 第4引数 - 平均 */
/* 第5引数 - 分散 */
void printData(double max, double min, double sum, double avg, double variance) {
	printf("最大値: %g\n", max);
	printf("最小値: %g\n", min);
	printf("合計  :%g\n", sum);
	printf("平均  :%g\n", avg);
	printf("分散  :%g\n", variance);

	return;
}