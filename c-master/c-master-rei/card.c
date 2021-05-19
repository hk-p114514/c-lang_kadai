#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "card.h"

void cardSet(Card card[])
{
  int i;

  for (i = 0; i < 52; i++) {
    card[i].num =           ;
    switch (      ) {
      case 0:              = 'H'; break;
      case 1:              = 'D'; break;
      case 2:              = 'S'; break;
      case 3:              = 'C'; break;
    }
  }

  return;
}

void cardPrint(Card card)
{
  printf("%c:%2d\n",          ,         );
  return;
}

//  配列 card[]を n回シャッフルする
//  1回のシャッフルは、2枚のカードの交換により行う

void cardShuffle(Card card[], int n)
{
  int i, j, k;               //  j,k: 発生した乱数を格納  
  Card temp;

  srand(time(NULL));         //  乱数の初期化 
  for (i = 0; i < n; i++) {
    j = rand()     ;       //  0〜51の間の乱数を１つ発生(rand()は0以上の整数乱数を返す)　
    k = rand()     ;       //  0〜51の間の乱数を１つ発生(rand()は0以上の整数乱数を返す)　
    temp    =        ;     // --+                         
    card[j] =        ;     //   |- 2枚のカードを交換      
    card[k] =     ;        // --+                         
  }
}
