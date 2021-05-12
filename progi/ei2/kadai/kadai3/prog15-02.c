#include <stdio.h>
int inputData(double data[]);

int main() {
	int n;               // データ数
	double data[ 1024 ]; // データ

	// 1. n個の実数を入力する
	n = inputData(data);

	// 2. 合計を求める
	int sum = 0; // 合計
	sum = sumData();

	// 3. 平均を求める
	int avg; // データの平均

	// 4. 分散を求める
	int variance; // 分散
	variance = findVariance();

	// 5. 大きい順に並べ替える
	sortDesc();

	// 6. 最大値と最小値を求める
	int max, min;
	max = data[ 0 ];
	min = data[ n ];

	// 7. n個の実数を表示する
	printNumbers();

	// 8. 最大値、最小値、合計、平均、分散を表示する
	printData();
	return (0);
}
/*
    inputData()
    渡された配列にデータを格納し、また入力されたデータ数を返す

    : Arugument - data[]
    : returnValue - 入力されたデータの個数
*/

int inputData(double data[]) {
	int n; // 入力するデータ数
};