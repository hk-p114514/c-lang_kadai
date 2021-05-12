/*
    数字付変数ー＞ 配列 {
        - メモリ上に連続で確保される領域
        ex)
            char a[5];
            ->
            [メモリ]
            :::::::::::::
            1001 | free |
            1002 | free |
            1003 | free |
            1004 | free |
            1005 | free |
            1006 | null |
            :::::::::::::
    }
*/

#include <stdio.h>
#include <hamako.h>

main()
{
    char s1[] = "John Smith(匿名希望)", s2[100];
    int len;
    
    len = getstring("enter a string : ", s2);

    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);

    return (0);
}