#include <stdio.h>
#include <hamako.h>

main()
{
    int a, b, c;
    a = getint("Enter a number 'a' : ");
    b = getint("Enter a number 'b' : ");
    c = getint("Enter a number 'c' : ");

    if (a == b && b == c) {
        printf("3つの値は等しいです\n");
    } else if (!(a == b) && !(b == c) && !(c == a)) {
        printf("３つの値は異なります\n");
    } else {
        printf("2つの値が等しいです\n");
    }
    return (0);
}