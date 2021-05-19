/*/* 1から10までの和を求めるプログラム  */
#include <stdio.h>

main()
{
  int i,s;

  do {
     i = 0;
     s = s + i++ ;
  } while (i < 10)

  printf("1から10までの和は"%d"です。\n", s);

  return(0);
}
