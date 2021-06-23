#include <stdio.h>
#define MIN_DAY (0)
#define MAX_HOUR (23)
#define MIN_HOUR (0)
#define MAX_MINUTES (59)
#define MIN_MINUTES (0)

typedef struct {
	int day;
	int hour;
	int minutes;
} Time;

Time inputTime(void);
Time addTime(Time time1, Time time2);
void printTime(Time time, char name[]);

int main() {
	Time sumTime = {0};
	Time input;
	while (1) {
		input = inputTime();

		// 入力値が全て0だったらループを抜ける
		if (input.day == 0 && input.hour == 0 && input.minutes == 0) {
			break;
		}

		sumTime = addTime(input, sumTime);
		printTime(sumTime, "sum");
	}

	return (0);
}

/* inputTime()
    概要:日数、時、分の値をキーボードから入力し、それらを持ったTime型の値を返す
*/
// 第一引数: 無し
// 返り値  : 入力値から作られたTime型の値
Time inputTime(void) {
	char buff[ 1024 ];
	Time input;

	printf("day, hour, minutes:");
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d, %d, %d", &input.day, &input.hour, &input.minutes);

	if (input.day < MIN_DAY || input.hour < MIN_HOUR || input.hour > MAX_HOUR ||
	    input.minutes < MIN_MINUTES || input.minutes > MAX_MINUTES) {
		printf("Input again.\n");
		input = inputTime();
	}

	return (input);
}

/* addTime()
    概要:2つのTime型の値を足し合わせる
*/
// 第一引数: Time型の値
// 第二引数: Time型の値
// 返り値  : 2つのTime型の値を足し合わせた結果
Time addTime(Time time1, Time time2) {
	Time added;
	added.day = time1.day + time2.day;
	added.hour = time1.hour + time2.hour;
	added.minutes = time1.minutes + time2.minutes;

	// 60で割った商分、時間を増やし,
	// 分そのものを、割ったあまりにする
	added.hour += (added.minutes / 60);
	added.minutes %= 60;

	// 24で割った商分、日を増やし,
	// 時間そのものを、割ったあまりにする
	added.day += (added.hour / 24);
	added.hour %= 24;

	return (added);
}

/* printTime()
    概要:渡されたTime型の値の全てのメンバ変数を出力する
*/
// 第一引数:Time型の値
// 返り値  : 無し
void printTime(Time time, char name[]) {
	printf("%s = %d %d %d\n", name, time.day, time.hour, time.minutes);

	return;
}