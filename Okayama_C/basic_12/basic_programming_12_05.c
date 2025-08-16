#include <stdio.h>

int main(void) {
    int num, i, j;

    printf("Enter a number: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        for (j = 0; j < num; j++) {
            if (i == j) {
                printf("X");
            } else {
                printf("O");
            }
        }
        printf("\n");
    }

    return (0);
}
