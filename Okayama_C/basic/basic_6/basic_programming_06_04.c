#include <stdio.h>

int main(void) {
    int num;

    printf("Enter the number: ");
    scanf("%d", &num);

    if (num % 2) {
        printf("%d is odd number\n", num);
    } else {
        printf("%d is even number\n", num);
    }

    return (0);
}
