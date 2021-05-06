// [CTRL+D]キーが押されるまでに入力した文字の行数を数える  

#include <stdio.h>

int main()
{
  // EOFと文字データを区別するため、
  // getchar()の返り値を受けるcはint型で宣言する
  int c;
  long lines = 0L;

  // 閉じ括弧「 ) 」 が一つ足りない
  // 代入演算子は「 == 」ではなく「 = 」
  while((c = getchar()) != EOF) {
    // 等号の演算子は「 = 」ではなく「 == 」
    // 文字型と文字列型は比較できないので、\nはシングルクォーテーションで囲う
    if (c == '\n') {
      lines++;
    }
  }
  // long型を意味する書式制御文字は「%d」ではなく「%ld」
  printf("Lines = %ld\n", lines);

  return(0);
}
