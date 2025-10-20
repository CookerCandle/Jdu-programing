#include <stdio.h>

int main(void) {
    int num, i;

    printf("Enter a positive number: ");
    scanf("%d", &num);

    printf("Divisor of %d are: \n", num);
    for (i = i; i <= num; i++) {
        if (num % i == 0) {
            printf("%d", i);
        }
    }
    if (num > 0) {
        printf("\n");
    }

    return (0);
}
