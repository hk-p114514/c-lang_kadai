#include <stdio.h>
#include <hamako.h>

void chLine(char c, int n);

void chRectangle(char c, int m, int n);

void chTriangle(char c, int m);

main()
{
    int m, n;
    char c;

    n = getint("列数: ");
    m = getint("行数: ");

    c = getcharacter("長方形を描く文字: ");
    printf("\n");
    chRectangle(c, m, n);

    c = getcharacter("三角形を描く文字: ");
    printf("\n");
    chTriangle(c, m);
    
    return (0);
}

void chLine(char c, int n) {
    /*
    Arugument : {
        c : 表示する文字
        n : 表示する文字の個数
    }

    function : 第一引数で指定した文字 c を第二引数で指定した数だけ横一列に表示する。
    ただし、表示後に改行はしない
    */

   for (int i = 0; i < n; i ++) {
       printf("%c", c);
   }

   return;
}

void chRectangle(char c, int m, int n) {
    /*
    Argument : {
        c : 表示する文字
        m : 表示する行数
        n : 表示する列数
    }

    function : 第一引数で指定した文字cで、第二、第三引数で指定したm行n列の長方形を表示する。
    ただし、表示後に改行する
    */

   while (n > 0) {
       chLine(c, m);
       printf("\n");
       n --;
   }

   return;
}

void chTriangle(char c, int m) {
    /*
    Argument : {
        c : 表示する文字
        m : 表示する段数
    }

    function : 第一引数で指定した文字cで、第二引数で指定したm段の二等辺三角形を表示する
    ただし、表示後に改行する
    */

   int floor = m + (m - 1); // 一番下の段の行数

   for (int i = 1; i <= m; i ++) {
       // 空白の数　＝　段数 - 今の段の数
       chLine(' ',m - i);

       // 文字の数　＝　段数　＋　前の段数
       chLine(c, i + (i - 1));

       // 改行
       printf("\n");
   }

   return;
}