#include <stdio.h>
#include <hamako.h>

main()
{
  int n;
  n = getint("Enter a number 'n' : ");

  if (n != 0) {
    if (n % 15 == 0) {
      printf("FizzBuzz\n");
    } else if (n % 3 == 0) {
      printf("Fizz\n");
    } else if (n % 5 == 0) {
      printf("Buzz\n");
    }
  }

  return (0);
}
