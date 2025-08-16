#include <stdio.h>

int main(void) {
    int num, i = 2;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Even numbers up to %d\n", num);
    while (i <= num) {
        printf("%d", i);
        i += 2;
    }
    printf("\n");

    return (0);
}
