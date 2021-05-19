#include <stdio.h>

void foo(int a[4][9]);

main()
{
  int a[4][9];

  printf("a:%d a[0]:%d a[0][0]:%d\n", sizeof(a), sizeof(a[0]), sizeof(a[0][0]));
  foo(a);

  return 0;
}

void foo(int a[4][9])
{
  printf("a:%d\n", sizeof(a));

  return;
}
