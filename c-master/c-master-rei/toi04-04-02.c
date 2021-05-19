#include <stdio.h>

main()
{
  int x = 1;
  int y = 2;

  x += 1;
  y *= x;
  printf("(x,y)=(%d,%d)\n", x, y);

  return (0);
}
