#include <stdio.h>

int main(void) {
    int i, j;

    int matrix[2][3] = {{10, 15, 25}, {3, 6}};

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("matrix[%d][%d]: %d\n", i, j, matrix[i][j]);
        }
    }

    return (0);
}
