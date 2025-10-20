#include <stdio.h>

int main(void) {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    if (num1 == num2) {
        printf("%d and %d is equal\n", num1, num2);
    } else {
        printf("%d and %d is not equal\n", num1, num2);
    }

    return (0);
}
