#include <stdio.h>

int main() {
    int num1, num2;
    int sum;

    printf("enter first number: ");
    scanf("%d", &num1);
    printf("enter second number: ");
    scanf("%d", &num2);

    // calc
    sum = num1 + num2;

    //out
    printf("sum: %d", sum);

    return 0;
}