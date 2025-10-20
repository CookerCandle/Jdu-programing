#include <stdio.h>

int main(void) {
    int num;

    do {
        printf("Enter a positeve number: ");
        scanf("%d", &num);
        if (num <= 0) {
            printf("Invalid input\n");
        }
    } while (num <= 0);

    printf("Reading %d backwards gives ", num);
    while (num > 0) {
        printf("%d", num % 10);
        num /= 10;
    }

    printf("\n");

    return (0);
}
