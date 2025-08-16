#include <stdio.h>

int main(void) {
    int num;

    printf("Enter the integer: ");
    scanf("%d", &num);

    if (num % 3 == 0) {
        printf("%d is a multiple of 3\n", num);
    } else if (num % 3 == 1) {
        printf("%d leaves a reminder of 1 when divided by 3\n", num);
    } else {
        printf("%d leaves a reminder of 2 when divided by 3\n", num);
    }

    return (0);
}
