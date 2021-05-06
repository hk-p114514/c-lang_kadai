#include <stdio.h>
#include <hamako.h>

main()
{
    int a, b;
    a = getint("Enter a number 'a' : ");
    b = getint("Enter a number 'b' : ");

    if ( a - b >= 11  || b - a >= 11) {
        printf("差は11以上です\n");
    } else {
        printf("差は10以下です\n");
    }

    return (0);
}
