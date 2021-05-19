#include <stdio.h>
#include <hamakou.h>

main()
{
  int x, y, ans;

  x = getint("Input x: ");
  y = getint("Input y: ");

  for (ans = 1;      ;     ) {
    ans = ans * x;
  }

  printf("x^y = %d\n", ans);

  return(0);
}
