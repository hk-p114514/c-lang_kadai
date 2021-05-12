/*
    ー 文字の扱い ー
    文字        ： 基本的に1文字のことを表す（単文字と区別する時もある）
    文字列      ： 1文字以上の文字の集まり
    文字定数    ： '「文字」' -> 例） a = 'a';
    表示        ： %c
    入力        ： getchar()        < -- 標準関数
                   getcharactor()   < -- hamako関数
    文字列定数 {
       - "「文字列」" -> （例）"abc" "a"
       - 内部的には最後に「null文字」が入っており、文字列の終わりを示している
       表示 : %s
       入力 : getstring(); -> ex) n = getstring("message : ", c);
            --> nには入力した文字数が、cには入力した文字列が格納される
            char s[100];
            s = "abc"; < - 出来無い
            char s[] = "abc" < - 出来る
    }
    */

#include <stdio.h>
#include <hamako.h>

main()
{
    char c, moji;
    c = 'c' - 'A';
    moji = getcharacter("enter a charactor : ");

    printf("c = %c, moji = %c \n", c, moji);

    char _str[100];
    int n;
    n = getstring("enter a string : ", _str);

    printf("str = %s, str's length = %d\n", _str, n);

    return(0);
}