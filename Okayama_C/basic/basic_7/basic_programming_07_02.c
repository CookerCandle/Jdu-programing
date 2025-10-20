#include <stdio.h>

int main(void) {
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    if (num % 2 == 0) {
        if (num % 3 == 0) {
            printf("%d is a multiple of 2, 3 and 6\n", num);
        } else {
            printf("%d is a multiple of 2\n", num);
        }
    }

    return (0);
}
