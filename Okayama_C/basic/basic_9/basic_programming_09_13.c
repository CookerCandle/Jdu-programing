#include <stdio.h>

int main(void) {
    int num1, num2, min, max;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    if (num1 > num2) {
        max = num1;
        min = num2;
    } else (
        max = num2;
        min = num1;
    )

    printf("the large number is %d\n", max)
    printf("the smaller number is %d\n", min)


    return (0);
}
