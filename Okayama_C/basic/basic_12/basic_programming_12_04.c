#include <stdio.h>

int main(void) {
    int num, i, j;

    printf("Enter a number: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        for (j = 0; j < num - i; j++) {
            printf("X");
        }
        for (j = i; j < num; j++) {
            printf("O");
        }
        printf("\n");
    }

    return (0);
}
