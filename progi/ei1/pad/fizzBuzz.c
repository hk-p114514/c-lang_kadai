#include <stdio.h>

int main() {
    int n, showI = 0;
    printf("What is the n ? : ");
    scanf("%d", &n);

    printf("Do you want to see i of counter ?\n");
    printf("No : 0 , Yes : 1\n");
    scanf("%d", &showI);
    int i, m3 = 0, m5 = 0, m15 = 0;
    for(i = 1; i <= n; i++) {
        if(showI)printf("i = %d\n", i);
        if(i % 3 == 0) {
            if(i % 5 == 0) {
                m15 ++;
                m3  ++;
                m5  ++;
                continue;
            } else {
                m3  ++;
                continue;
            }
        }
        if(i % 5 == 0) m5 ++;
    }

    printf("m3 = %d\n", m3);
    printf("m5 = %d\n", m5);
    printf("m15 = %d\n", m15);

    return (0);
}