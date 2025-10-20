#include <stdio.h>

int main(void) {
    int num, i, j;

    printf("Enter a number: ");
    scanf("%d",  &num);

    printf("  |");
    for (j = 1; j <= num; j++) {
        printf("%2d", j);
    }
    printf("\n");

    printf("--+");
    for (j = 1; j <= num; j++) {
        printf("---");
    }
    printf("\n");

    for (i = 1; i <= num; i++) {
        printf("%d |", i);
        for (j = 1; j <= num; j++) {
            printf("%2d", i * j);
        }
        printf("\n");
    }

    return (0);
}
