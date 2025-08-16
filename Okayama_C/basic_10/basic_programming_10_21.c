#include <stdio.h>

int main(void) {
    int num, i = 0;

    printf("Enter a positive number: ");
    scanf("%d", &num);

    do {
        printf("%d", i++);
    } while (i <= num);
    printf("\n");

    return (0);
}
