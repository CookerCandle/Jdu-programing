#include <stdio.h>

int main(void) {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    if (num1 == num2 * 10) {
        printf("%d is 10 times %d\n", num1,num2);
    } else {
        printd("%d is not 10 times %d\n", num1, num2);
    }

    return (0);
}
