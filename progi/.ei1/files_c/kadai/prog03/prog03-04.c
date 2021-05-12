#include <stdio.h>
#include <hamako.h>

main()
{
    int n, i;
    char c[256];
    n = getstring("Input c : ", c);

    for (i = 0; i < n; i ++) {
        int c_num = (int)c[i];
        if (c_num >= 'A' && c_num <= 'Z') {
            c[i] += ('a' - 'A');
        } else if (c_num >= 'a' && c_num <= 'z') {
            c[i] -= ('a' - 'A');
        }
    }

    printf("%s\n", c);

    return (0); 
}