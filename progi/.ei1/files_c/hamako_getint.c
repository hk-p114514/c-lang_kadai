#include <stdio.h>
#include <hamako.h>

main()
{
  int a;
  a = getint("aの値を入力してください : ");
  printf("a = %d \n", a);

  return (0);
}

