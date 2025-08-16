#include <stdio.h>

int main(void) {
    int num;

    printf("Enter the number: ");
    scanf("%d" &num);

    if (num % 5) {
        printf("%d is not divisible by 5\n", num);
    }

    return (0);
}
