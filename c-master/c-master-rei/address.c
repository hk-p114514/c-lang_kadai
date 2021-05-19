#include <stdio.h>

main()
{
  int x = 10, *p;

  p = &x;

  printf("    x = %d\n", x);
  printf("   *p = %d\n", *p);

  printf("   &x = %p\n", &x);
  printf("    p = %p\n", p);

  return(0);
}
