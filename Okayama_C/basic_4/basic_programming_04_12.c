#include <stdio.h>

int main(void) {
    double num1 = 22.1, num2 = 7.5;

    printf("num1 = %f: num2 = %f\n", num1, num2)
    printf("%f + %f = %f\n", num1, num2, num1 + num2);
    printf("%f - %f = %f\n", num1, num2, num1 - num2);
    printf("%f * %f = %f\n", num1, num2, num1 * num2);
    printf("%f / %f = %f\n", num1, num2, num1 / num2);
    printf("+%f = %f\n", num2, +num2);
    printf("-%f = %f\n", num2, -num2);
     
    return (0);
}
