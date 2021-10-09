#include <stdio.h>
typedef enum
{
	Sun,
	Mon,
	Tue,
	Wed,
	Thu,
	Fri,
	Sat
} WeekDay;

int isLeapYear(int year);

int main() {
	WeekDay w;
	char *dayNames[] =
	    {"日曜日", "月曜日", "火曜日", "水曜日", "木曜日", "金曜日", "土曜日"};

	// input date
	char buff[ 1024 ];
	int year, month, day;
	printf("Input day (yyyy/mm/dd): ");
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d/%d/%d", &year, &month, &day);

	// check leap years
	// month			1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12
	int dayOfMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (isLeapYear(year) == 1) {
		dayOfMonth[ 1 ] = 29;
	}

	int sumDays = 0;

	// calc year/1/1 ~ year/month/day
	for (int i = 0; i < month - 1; i++) {
		sumDays += dayOfMonth[ i ];
	}

	sumDays += day;

	// calc 1/1/1 ~ (year - 1)/12/31
	for (int now = 1; now < year; now++) {
		int maxDayOfYear = 365;
		if (isLeapYear(now) == 1) {
			maxDayOfYear = 366;
		}

		sumDays += maxDayOfYear;
	}

	w = sumDays % 7;

	putchar('\n');
	printf("%s\n", dayNames[ w ]);

	return (0);
}

int isLeapYear(int year) {
	int isLeapYear = 0;
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
		isLeapYear = 1;
	}

	return (isLeapYear);
}