#include <stdio.h>
#define DATE_SIZE 2

typedef struct {
	int year;
	int month;
	int day;
} Date;

Date laterDate(Date date1, Date date2);

int main() {
	Date date1, date2;

	char buff[ 1024 ];

	printf("日付1 (yyyy/mm/dd) : ");
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d/%d/%d", &date1.year, &date1.month, &date1.day);

	printf("日付2 (yyyy/mm/dd) : ");
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d/%d/%d", &date2.year, &date2.month, &date2.day);

	Date later = laterDate(date1, date2);

	printf("%d/%02d/%02d\n", later.year, later.month, later.day);

	return (0);
}

/*========================================*/

Date laterDate(Date date1, Date date2) {
	Date laterDate;

	// 年が異なる場合は年が大きい方を返す
	if (date1.year > date2.year) {
		laterDate = date1;
	} else if (date1.year < date2.year) {
		laterDate = date2;
	} else {
		// 年が同じ場合は、月が大きい方を返す
		if (date1.month > date2.month) {
			laterDate = date1;
		} else if (date1.month < date2.month) {
			laterDate = date2;
		} else {
			// 年が同じで月も同じ場合は日が大きい方を返す
			if (date1.day > date2.day) {
				laterDate = date1;
			} else {
				laterDate = date2;
			}
		}
	}

	return (laterDate);
}
