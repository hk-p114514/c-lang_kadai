#include <stdio.h>

void twice(int x);

main()
{
  int x = 10;

  printf("main : x = %d\n", x);
  twice(x);
  printf("main : x = %d\n", x);

  return(0);
}

void twice(int x)
{
  printf("twice: x = %d\n", x);
  x = x * 2;
  printf("twice: x = %d\n", x);

  return;
}
