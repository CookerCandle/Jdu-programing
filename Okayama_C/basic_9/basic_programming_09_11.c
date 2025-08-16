#include <stdio.h>

int main(void) {
    int num1, num2, difference;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    if (num1 > num2) {
        difference = num1 - num2;
    } else {
        difference = num2 - num1;
    }

    printf("The difference between the numbers is: %d\n", difference);

    return (0);
}
