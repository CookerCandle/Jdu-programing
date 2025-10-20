#include <stdio.h>

int main(void) {
    int num1 = 20, num2 = 7;

    printf("%d + %d = %d\n", num1, num2, num1 + num2);
    printf("%d - %d = %d\n", num1, num2, num1 - num2);
    printf("%d * %d = %d\n", num1, num2, num1 * num2);
    printf("%d / %d = %d\n", num1, num2, num1 / num2);
    printf("%d %% %d = %d\n", num1, num2, num1 % num2);
    printf("+%d = %d\n", num2, +num2);
    printf("-%d = %d\n", num2, -num2);
     
    return (0);
}
