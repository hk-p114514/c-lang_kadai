#include <stdio.h>

int main() {
    char str[5][10] = {
        {""},
        {""}
    };

    for (int i = 0; i < (sizeof(str) / sizeof(str[0])); i++) {
        printf("%s\n", str[i]);
    }

    return (0);
}