#include <stdio.h>

int main(void) {
    int num;

    printf("Enter the integer: ");
    scanf("%d", &num);

    switch (num % 3) {
        case 0:
            printf("%d is a multiple of 3\n", num);
            break;
        case 1:
            printf("%d leaves a reminder of 1 when divided by 3\n", num);
            break;
        case 2:
            printf("%d leaves a reminder of 2 when divided by 3\n", num);
            break;
    }

    return (0);
}
