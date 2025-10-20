#include <stdio.h>

int main(void) {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, num2);

    if (num > num2) {
        printf("The large number is %d", num1);
    } else {
        printf("The large number is %d", num2);
    }

    return (0);
}
