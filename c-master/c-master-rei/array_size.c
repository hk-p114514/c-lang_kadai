#include <stdio.h>

main()
{
  int a[4][9];

  printf("a:%d a[0]:%d a[0][0]:%d\n", sizeof(a), sizeof(a[0]), sizeof(a[0][0]));

  return 0;
}
