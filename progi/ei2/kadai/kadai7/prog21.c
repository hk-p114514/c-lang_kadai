#include <stdio.h>
#define MAX_STUDENTS 100   // 生徒の最大人数
#define MAX_NAME_LENGTH 20 // 名字、名前のそれぞれの最大文字数
#define MAX_SCORE 100      // 各科目の満点
#define SUBJECTS 3         // 教科の数

typedef struct {
	/* 名前を格納する配列(空白を一つ含むため、想定している最大文字数 + 1) */
	char name[ (MAX_NAME_LENGTH * 2) + 1 ];
	int rank;              // 生徒の順位
	int score[ SUBJECTS ]; // 各教科の得点(0: 国語, 1: 数学, 2: 英語)
	int studentNumber;
} Exam;

void setName(Exam *student, char name1[], char name2[]);
char *getName(Exam *student, char name[]);
void setSubjectScore(Exam *student, int sbj, int score);
int getSubjectScore(Exam *student, int sbj);
int getScoreSum(Exam *student);
void setRank(Exam *student, int rank);
int getRank(Exam *student);

int inputData(Exam *students[]);
void calcRank(Exam *students[], int n);

int main() {
	// 入力されたデータの個数（実際に処理する人数）
	int n;

	// 各生徒の情報
	Exam students[ MAX_STUDENTS ];

	// 1.データの入力
	n = inputData(&students);

	// 要素数超過によるエラー処理
	if (n > MAX_STUDENTS) {
		printf("\n!!! エラー : データ数が多すぎます !!!\n");
		printf("入力されたデータ数%dはデータの最大数%dを超えています\n", n, MAX_STUDENTS);
		return (1);
	}

	// 2.各生徒の順位を求める
	calcRank(&students, n);

	// 3.各生徒の得点の平均を求める

	// 4.試験成績一覧表を表示

	return (0);
}

/* inputData()
    概要:生徒の生徒番号、名字、名前、国語、数学、英語の点数を入力する
*/
// 第1引数 : データを格納する各生徒の情報を指すポインタ配列
// 返り値  : 入力されたデータの数（人数）
int inputData(Exam *students[]) {
	int n;
	char buff[ 256 ];

	// 1.入力するデータの個数を入力する
	printf("Input n :");
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d", &n);
	int score[ 3 ], studentNumber;
	char name1[ MAX_STUDENTS + 1 ], name2[ MAX_STUDENTS + 1 ];

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
void calcRank(Exam *students[], int n) {
	for (int i = 0; i < n; i++) {
		int rank = n;
		int sum = getScoreSum(students[ i ]);
		for (int j = 0; j < n; j++) {
			if (i != j && sum > getScoreSum(students[ j ])) {
				rank--;
			}
		}
		setRank(students[ i ], rank);
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
	/* name1が姓、name2が名なので、並びとしては、 「name1 name2」となればよい*/
	int i;
	for (i = 0; name1[ i ] != '\0'; i++) {
		student->name[ i ] = name1[ i ];
	}

	// 姓と名の間に一つ空白を入れる
	student->name[ i ] = ' ';

	for (int j = 0; name2[ j ] != '\0'; j++) {
		student->name[ j + i + 1 ] = name2[ j ];
	}

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
	for (int i = 0; student->name[ i ] != '\0'; i++) {
		name[ i ] = student->name[ i ];
	}

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