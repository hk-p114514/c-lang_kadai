#include <stdio.h>

int main()
{
    char array[3][4] = {
        {'a', 'b', 'c', 'd'},
        {'e', 'f', 'g', 'h'},
        {'h', 'i', 'j', 'k'}
    };

    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 4; j ++) {
            printf("No.%d:%d character is %c\n", i, j, array[i][j]);
        }
        printf("#####################\n");
    }

    return(0);
}