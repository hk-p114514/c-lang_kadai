#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 100   // 生徒の最大人数
#define MAX_NAME_LENGTH 20 // 名字、名前のそれぞれの最大文字数
#define MAX_SCORE 100      // 各科目の満点
#define SUBJECTS 3         // 教科の数

typedef struct {
	// 名前を格納する配列(空白を一つ含むかつ安全のため余裕を持って、想定している最大文字数+10)
	char name[ (MAX_NAME_LENGTH * 2) + 10 ];
	int rank;              // 生徒の順位
	int score[ SUBJECTS ]; // 各教科の得点(0: 国語, 1: 数学, 2: 英語)
} Exam;

void setName(Exam *student, char name1[], char name2[]);
char *getName(Exam *student, char name[]);
void setSubjectScore(Exam *student, int sbj, int score);
int getSubjectScore(Exam *student, int sbj);
int getScoreSum(Exam *student);
void setRank(Exam *student, int rank);
int getRank(Exam *student);

int inputData(Exam *students);
void calcRank(Exam *students, int n);
void printTable(Exam *students, int n);
void printDegreeDistributionTable(Exam *students, int n);
int searchRange(int n, int array[], int min, int max);
void fillInTheBlanks(int max, int isFilled);

int main() {
	// 入力されたデータの個数（実際に処理する人数）
	int n;
	// 各生徒の情報
	/* 添字を１から利用するので想定最大数＋１の要素数を確保する */
	Exam students[ MAX_STUDENTS + 1 ];

	// 1.データの入力
	n = inputData(students);

	// 要素数超過によるエラー処理
	if (n > MAX_STUDENTS) {
		printf("\n!!! エラー : データ数が多すぎます !!!\n");
		printf("入力されたデータ数%dはデータの最大数%dを超えています\n", n, MAX_STUDENTS);
		return (1);
	}

	// 2.各生徒の順位を求める
	calcRank(students, n);

	// 3.試験成績一覧表を表示
	printTable(students, n);

	// 4.度数分布表を表示する
	printDegreeDistributionTable(students, n);

	return (0);
}

/* inputData()
    概要:生徒の生徒番号、名字、名前、国語、数学、英語の点数を入力する
*/
// 第1引数 : データを格納する各生徒の情報を指すポインタ配列
// 返り値  : 入力されたデータの数（人数）
int inputData(Exam *students) {
	int n;
	char buff[ 256 ];

	// 1.入力するデータの個数を入力する
	printf("Input n :");
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d", &n);
	int score[ 3 ], studentNumber;
	char name1[ 256 ], name2[ 256 ];

	// 2.各生徒ごとのデータを受け取る
	for (int i = 0; i < n; i++) {
		printf("%d番目の入力\n", i + 1);
		printf("生徒番号 名字 名前 国語の点数 数学の点数 英語の点数\n");
		fgets(buff, sizeof(buff), stdin);
		sscanf(
		    buff,
		    "%d %s %s %d %d %d",
		    &studentNumber,
		    name1,
		    name2,
		    &score[ 0 ],
		    &score[ 1 ],
		    &score[ 2 ]);

		// 2.1受け取ったデータを割り付ける
		// 2.1.1名前を割り付ける
		setName(&students[ studentNumber ], name1, name2);

		// 2.1.2各点数を割り付ける
		for (int i = 0; i < SUBJECTS; i++) {
			setSubjectScore(&students[ studentNumber ], i, score[ i ]);
		}
	}
	return (n);
}

/* calcRank()
    概要:各生徒の合計得点に基づく順位を求め、格納する
*/
// 第1引数: 順位を求める生徒のデータを指すポインタ
// 第2引数: 生徒の人数
// 返り値  : なし
void calcRank(Exam *students, int n) {
	int rank;
	for (int i = 1; i <= n; i++) {
		rank = 1;
		for (int j = 1; j <= n; j++) {
			if (getScoreSum(&students[ i ]) < getScoreSum(&students[ j ])) {
				rank++;
			}
		}
		setRank(&students[ i ], rank);
	}

	return;
}

/* printTable()
    概要:成績一覧を生徒番号順に表示する
*/
// 第1引数:成績を表示する生徒を指すポインタ
// 第2引数:生徒の人数
// 返り値 : なし
void printTable(Exam *students, int n) {
	int total[ SUBJECTS + 1 ] = {};
	// 出力する項目を出力
	printf(
	    "%s %s     %40s    %s    %s    %s    %s    %s",
	    " NO "
	    "氏名",
	    "",
	    "国語",
	    "数学",
	    "英語",
	    "合計",
	    "順位",
	    "平均");
	putchar('\n');

	// 生徒個人のデータをそれぞれ表示
	for (int i = 1; i <= n; i++) {
		// 生徒番号の表示
		printf("%3d ", i);

		// 名前の表示
		char name[ (MAX_STUDENTS * 2) + 10 ];
		getName(&students[ i ], name);
		printf("%s", name);

		// 文字数を合わせ
		fillInTheBlanks((MAX_NAME_LENGTH * 2) + 1, strlen(name));

		// 各教科の点数、合計、順位を表示
		printf(
		    "%4d     %4d     %4d     %4d     %4d",
		    getSubjectScore(&students[ i ], 0), // 国語の点数
		    getSubjectScore(&students[ i ], 1), // 数学の点数
		    getSubjectScore(&students[ i ], 2), // 英語の点数
		    getScoreSum(&students[ i ]),        // 合計
		    getRank(&students[ i ])             // 順位
		);

		// 全生徒の各教科の合計を加算しておく
		for (int j = 0; j < SUBJECTS; j++) {
			total[ j ] += getSubjectScore(&students[ i ], j);
		}

		// 各生徒の点数の合計と教科の数から、点数の平均を出す
		double avg = (double)getScoreSum(&students[ i ]) / (double)SUBJECTS;

		// 平均を表示
		if (avg == 0) {
			printf("  %s%.2lf", "    ", avg);
		} else if (avg >= 100) {
			printf("    %.2lf", avg);
		} else if (avg >= 10) {
			printf(" %s%.2lf", "    ", avg);
		} else {
			printf(" %s%.2lf", "     ", avg);
		}

		putchar('\n');
	}
	putchar('\n');

	// 全生徒の点数の合計の合計を出す
	for (int i = 1; i <= n; i++) {
		total[ SUBJECTS ] += getScoreSum(&students[ i ]);
	}

	// 全体の合計値を表示
	printf("%35s%s", "", "合計");
	for (int i = 0; i < SUBJECTS + 1; i++) {
		printf("\t%3d", total[ i ]);
	}
	putchar('\n');

	// 全体の平均値を表示
	printf("%35s%s", "", "平均");
	for (int i = 0; i < SUBJECTS + 1; i++) {
		printf("\t%.2lf", (double)total[ i ] / (double)n);
	}
	putchar('\n');

	return;
}

/* printDegreeDistributionTable()
    概要:度数分布表を表示する
*/
// 第1引数:度数分布表に使用する各生徒のデータを指すポインタ
// 第2引数:生徒の人数
// 返り値  : なし
void printDegreeDistributionTable(Exam *students, int n) {
	int min = 0;
	int max = 49;
	int change = 50;
	int maxRange = SUBJECTS * MAX_SCORE;
	int sum[ MAX_STUDENTS ];

	// 全生徒の点数の合計だけをコピーする
	for (int i = 0; i < n; i++) {
		sum[ i ] = getScoreSum(&students[ i + 1 ]);
	}

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

/* searchRange()
    概要:渡された配列の中に特定の範囲の値がいくつあるか調べる
*/
// 第1引数: データの個数
// 第2引数: 調べるデータ
// 第3引数: 範囲の最小値
// 第4引数: 範囲の最大値
// 返り値  : 特定した値の個数
int searchRange(int n, int data[], int min, int max) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (data[ i ] >= min && data[ i ] <= max) {
			count++;
		}
	}

	return (count);
}

/* isFilled()
    概要:渡された最大値と既に埋められた文字数から、字数合わせをする
*/
// 第1引数:字数合わせをする行の最大文字数
// 第2引数:既に埋められた文字数
// 返り値  : なし
void fillInTheBlanks(int max, int isFilled) {
	// 文字数を合わせ
	int blanks = max - isFilled;
	for (int j = 0; j < blanks; j++) {
		putchar(' ');
	}

	return;
}

/*========================================*/

/* setName()
    概要:name1とname2からなる氏名を指定した生徒に格納する
*/
// 第1引数 : 氏名を格納する生徒１人分のデータを指すポインタ
// 第2引数 : 姓
// 第3引数 : 名
// 返り値  : なし
void setName(Exam *student, char name1[], char name2[]) {
	/* name1が姓、name2が名なので、並びとしては、 「name1name2」となればよい*/
	int name1Len = strlen(name1);
	int name2Len = strlen(name2);

	// 名前の文字数が最大より大きかったら
	if (name1Len > MAX_NAME_LENGTH) {
		// 最大文字数までのみを取り込む
		name1[ MAX_NAME_LENGTH ] = '\n';
		sscanf(name1, "%s", name1);
	}

	if (name2Len > MAX_NAME_LENGTH) {
		name2[ MAX_NAME_LENGTH ] = '\n';
		sscanf(name2, "%s", name2);
	}

	strcat(name1, " ");
	strcat(name1, name2);
	strcpy(student->name, name1);

	return;
}

/* *getName()
    概要:指定した生徒のデータから、氏名をname[]に取り出す。
    取り出される氏名の形式は、"姓 名"または "FirstName LastName"
*/
// 第1引数 : 氏名を取り出す生徒一人分のポインタ
// 第2引数 : 取り出した氏名を格納する文字配列
// 返り値  : 取り出した氏名を指すポインタ(nameそのもの)
char *getName(Exam *student, char name[]) {
	strcpy(name, student->name);

	return (name);
}

/* setSubjectScore()
    概要:指定した生徒に、科目番号sbjの科目の得点scoreを格納する
*/
// 第1引数 : 得点を格納する生徒一人分のデータを指すポインタ
// 第2引数 : 対象科目の科目番号(0: 国語、1: 数学、2: 英語)
// 第3引数 : 科目番号sbjの科目の得点
// 返り値  : なし
void setSubjectScore(Exam *student, int sbj, int score) {
	student->score[ sbj ] = score;
	return;
}

/* getSubjectScore()
    概要:指定した生徒のデータから科目番号sbjのの科目の得点を取得する
*/
// 第1引数 : 得点を格納する生徒１人分のデータを指すポインタ
// 第2引数 : 対象科目の科目番号(0: 国語、1: 数学、2: 英語)
// 第3引数 : 科目番号sbjの科目の得点
// 返り値  : 生徒studentの科目番号sbjの得点
int getSubjectScore(Exam *student, int sbj) {
	return (student->score[ sbj ]);
}

/* getScoreSum()
    概要:指定した生徒のデータから全科目の合計得点を取得する
*/
// 第1引数 : 得点を取り出す生徒一人分のデータを指すポインタ
// 返り値  : 全科目の合計得点
int getScoreSum(Exam *student) {
	int sum = 0;
	for (int i = 0; i < SUBJECTS; i++) {
		sum += student->score[ i ];
	}

	return (sum);
}

/* setRank()
    概要:指定した生徒に、合計得点に基づく順位rankを格納する
*/
// 第1引数 : 順位を格納する生徒一人分のデータを指すポインタ
// 第2引数 : 合計得点に基づく順位
// 返り値  : なし
void setRank(Exam *student, int rank) {
	student->rank = rank;
}

/* getRank()
    概要:指定した生徒のデータから合計点に基づく順位を取得する
*/
// 第1引数 : 順位を取り出す生徒一人分のデータを指すポインタ
// 返り値  : 合計得点に基づく生徒studentの順位
int getRank(Exam *student) {
	return (student->rank);
}
