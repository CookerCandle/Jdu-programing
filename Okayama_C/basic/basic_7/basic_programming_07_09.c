#include <stdio.h>

int main(void) {
    int num;

    printf("Enter the number: ");
    scanf("%d", &num);

    if (num > 0) {
        if (num % 2 == 0) {
            printf("%d is even number\n", num);
        } else {
            printf("%d is odd number\n", num);
        }
    } else {
        printf("Please Enter a positive number\n")
    }

    return (0);
}
