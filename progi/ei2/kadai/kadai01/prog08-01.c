#include <stdio.h>
#include <hamakou.h>

int sumConsInt(int n);

main()
{
  int n;

  n = getint("Input n: ");
  printf("Ans = %d\n", sumConsInt(n));

  return(0);
}

int sumConsInt(int n) {
  // 引数：nは整数
  // 戻り値：n以下の連続する整数の和

  int ans;

  if (n >= 0) {
    // n >= ならば n 以下の連続する整数の和を求める
    ans = 0;
    for(int i = 0; i <= n; i ++) {
      ans += i;
    }
  } else {
    // n < 0 ならば -1 を返す
    ans = -1;
  }

  return (ans);
}