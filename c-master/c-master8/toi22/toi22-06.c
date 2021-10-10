#include <stdio.h>
int openFileCheck(FILE *file);

int main(int argc, char *argv[]) {
	FILE *input = fopen(argv[ 1 ], "r");
	if (openFileCheck(input) == 1) {
		return (1);
	}
	FILE *ans = fopen("sum.ans", "w");
	if (openFileCheck(ans) == 1) {
		fclose(input);
		return (1);
	}

	int numberOfData = 0;
	int sum = 0;
	char buff[ 1024 ];

	// Read data file
	while (fgets(buff, sizeof(buff), input) != NULL) {
		int data;
		sscanf(buff, "%d", &data);
		sum += data;
		numberOfData++;
	}

	double avg = (double)sum / (double)numberOfData;

	// show the result
	printf("データ数: %d\n", numberOfData);
	printf("合計\t: %d\n", sum);
	printf("平均\t: %.1lf\n", avg);

	// write the result to output
	fprintf(ans, "データ数: %d\n", numberOfData);
	fprintf(ans, "合計\t: %d\n", sum);
	fprintf(ans, "平均\t: %.1lf\n", avg);

	fclose(input);
	fclose(ans);

	return (0);
}

int openFileCheck(FILE *file) {
	if (file == NULL) {
		printf("ファイルをオープンできませんでした\n");
		return (1);
	}

	return (0);
}