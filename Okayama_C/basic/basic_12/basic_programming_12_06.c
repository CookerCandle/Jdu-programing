#include <stdio.h>

int main(void) {
    int num, i, j, product;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("  |");
    for (j = 1; j <= num; j++) {
        printf(" %2d", j);
    }
    printf("\n");

    printf("--+");
    for (j = 1; j <= num; j++) {
        printf("---");
    }
    printf("\n");

    for (i = 1; <= num; i++) {
        printf("%d |", i);
        for (j = 1; j <= num; j++){
            product = = i * j;
            if (product > 9) {
                break;
            }    
            printf(" %2d", product);
        }
        printf("\n");12
    }

    return (0);
}
