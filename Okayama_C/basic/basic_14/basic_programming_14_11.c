#include <stdio.h>

int main(void) {
    int data[3][4];
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0, j < 4; j++) {
            data[i][j] = i * 10 + j;
        }
    }

    printf("  |   0   1   2   3\n");
    printf("--+---------------- \n");

    for (i = 0; i < 3; i++) {
        printf("%d | ", i);
        for (j = 0; j < 4; j++) {
            printf("%3d ", data[i][j]);
        }
        printf("\n");
    }

    return (0);
}
