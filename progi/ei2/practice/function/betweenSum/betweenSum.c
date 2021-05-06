#include <stdio.h>
#include <hamako.h>

int betweenSum(int left, int right);

main()
{
  int left, right;

  left = getint("left: ");
  right = getint("right: ");

  printf("%d～%d までの和: %d\n", left, right, betweenSum(left, right));

  return(0);
}

int betweenSum(int left, int right)
{
  // [引数] : left - 区間の左端の整数、 right - 区間の右端の整数
  // [戻り値] : 区間の左端の整数から右端の整数までの連続した整数の和

  // 区間の左端から右端までの整数の和を入れる変数
  int sum = 0;

  for (int i = left; i <= right; i ++) {
    sum += i;
  }

  return (sum);
}
