#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *input = fopen(argv[ 1 ], "r");
	FILE *ans = fopen("sum.ans", "w");

	if (input == NULL || ans == NULL) {
		// Error
		printf("Error opening input file.\n");
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
	fprintf(ans, "データ数 : %d\n", numberOfData);
	fprintf(ans, "合計\t: %d\n", sum);
	fprintf(ans, "平均\t: %.1lf\n", avg);

	fclose(input);
	fclose(ans);

	return (0);
}
