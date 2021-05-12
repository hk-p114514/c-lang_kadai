#include <stdio.h>
int getint(char message[99]) {
    int elem;
    printf("%s", message);
    scanf("%d", &elem);
    return elem;
}