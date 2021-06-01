// #include <hamakou.h>
#include <stdio.h>

int isLeapYear(int year);

int main() {
	int year;
	char buff[ 1024 ];

	printf("西暦年: ");
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d", &year);

	// year = getint("西暦年: ");
	putchar('\n');
	switch (isLeapYear(year)) {
	case 0:
		printf("平年\n");
		break;
	case 1:
		printf("閏年\n");
		break;
	}
	return (0);
}

/* isLeapYear()
  概要:渡された四桁の整数を西暦年としてその年がうるう年か平年かを判別する
*/
// 第一引数: 判別する西暦年(四桁の整数を)
// 返り値  : 引数の西暦年がうるう年なら1を、平年なら0を返す
int isLeapYear(int year) {
	int isLeap;
	if (year % 400 == 0) {
		isLeap = 1;
	} else if (year % 100 == 0) {
		isLeap = 0;
	} else if (year % 4 == 0) {
		isLeap = 1;
	} else {
		isLeap = 0;
	}

	return (isLeap);
}