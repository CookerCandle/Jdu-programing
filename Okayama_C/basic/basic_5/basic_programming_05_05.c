#include <stdio.h>

int main(void) {
    int num1, num2;

    printf("Enter two numbers (num1, num2): ");
    scanf("%d %d", &num1, &num2);

    if (num1 != num2) {
        printf("%d and %d not equal\n", num1, num2)
    }

    return (0);
}
