#include <stdio.h>

typedef struct {
	int rank;
	int japanese;
	int math;
	int english;
} Exam;

void setName(Exam *student, char name1[], char name2[]);
char *getName(Exam *student, char name[]);
void setSubjectScore(Exam *student, int sbj, int score);
int getSubjectScore(Exam *student, int sbj);
int getScoreSum(Exam *student);

int main() {

	return (0);
}

/* setName()
    概要:name1とname2からなる氏名を指定した生徒に格納する
*/
// 第1引数 : 氏名を格納する生徒１人分のデータを指すポインタ
// 第2引数 : 姓
// 第3引数 : 名
// 返り値  : なし
void setName(Exam *student, char name1[], char name2[]) {
}

/* *getName()
    概要:指定した生徒のデータから、氏名をname[]に取り出す。
    取り出される氏名の形式は、"姓 名"または "FirstName LastName"
*/
// 第1引数 : 氏名を取り出す生徒一人分のポインタ
// 返り値  : returnValue