#include <stdio.h>

int main() {

    int zaiseki[3][8] = {
        {41,40,40,40,40,41,41,42},
        {39,38,34,40,37,39,35,39},
        {30,39,31,40,38,40,33,36}
    };

    int minGrade, maxGrade, minGroup, maxGroup;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 8; j ++) {
            if (zaiseki[i][j] > zaiseki[maxGrade][maxGroup]) {
                maxGrade = i;
                maxGroup = j;
            } else if (zaiseki[i][j] < zaiseki[minGrade][minGroup]) {
                minGrade = i;
                minGroup = j;
            }
        }
    }

    printf("在籍人数が最も少ないクラスは%d年%d組で、%d人です\n", minGrade + 1, minGroup + 1, zaiseki[minGrade][minGroup]);
    printf("在籍人数が最も多いクラスは%d年%d組で、%d人です\n", maxGrade + 1, maxGroup + 1, zaiseki[maxGrade][maxGroup]);
}