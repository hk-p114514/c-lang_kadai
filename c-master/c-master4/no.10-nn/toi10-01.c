#include <stdio.h>

int main()   {
    int startTime, endTime, startMinute, endMinute;

    printf("時刻 = ");
    scanf("%d:%d %d:%d", &startTime, &startMinute, &endTime, &endMinute);

    //  経過時間   , 分単位,      , 秒単位
    int betweenTime, betweenMinute, betweenSecond;

    // 終了時刻 - 開始時刻 (時間単位)
    betweenTime = endTime - startTime;

    // 開始時刻と終了時刻の分単位の差
    betweenMinute = endMinute - startMinute;

    // 時間単位の値を分単位に変換し、合計を算出する
    betweenMinute += betweenTime * 60;

    // 分単位に変換した合計値を、秒単位に変換する。
    betweenSecond = betweenMinute * 60;

    printf("%d:%dから%d:%dまでは、%d分または%d秒です\n",startTime, startMinute, endTime, endMinute, betweenMinute, betweenSecond);

    return (0);
}
