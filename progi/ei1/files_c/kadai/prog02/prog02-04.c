#include <stdio.h>
#include <hamako.h>

main()
{
  float max, min, sum, avg, a[100];
  int n, i;
  sum = 0;

  n = getint("Input n: ");
  if (n <= 0 || n > 100) {
    printf("データの数が正しくありません\n");
  }
  
  i = 0;
  while(i < n) {
    printf("a[%d] = ", i);
    a[i] = getfloat("");
    sum += a[i];
    i ++;
  }

  max = a[0];
  min = a[0];
  avg = sum / n;
  i = 1;
  while ( i < n ) {
    if (a[i] > max ) {
      max = a[i];
    } else if (a[i] < min ) {
        min = a[i];
    }
    i = i + 1;
  }
  printf("max = %g\n", max);
  printf("min = %g\n", min);
  printf("sum = %g\n", sum);
  printf("avg = %g\n", avg);

  return (0);
}

