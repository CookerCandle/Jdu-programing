#include <stdio.h>

int main(void) {
    int matrix = [2][3];

    matrix[0][0] = 10;
    matrix[0][2] = 25;

    printf("matrix[0][2]: %d\n", matrix[0][2]);
    printf("matrix[0][0]: %d\n", matrix[0][0]);

    printf("matrix[0][1]: %d\n", matrix[0][1]);

    return (0);
}
