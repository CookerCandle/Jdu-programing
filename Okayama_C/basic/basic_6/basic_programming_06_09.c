#include <stdio.h>

int main(void) {
    int num;

    printf("Enter the number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("%d is a negative number\n", num);
    } else {
        printf("%d is not a negative number\n", num);
    }

    return (0);
}
