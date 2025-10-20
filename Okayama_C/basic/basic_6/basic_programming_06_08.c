#include <stdio.h>

int main(void) {
    int num;

    printf("Enter the number: ");
    scanf("%d", &num);

    if ((num % 10) == 5) {
        printf("The last digit of %d is 5\n", num);
    } else {
        printf("The last digit of %d is not 5\n", num);
    }

    return (0);
}
