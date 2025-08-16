#include <stdio.h>

int main(void) {
    int num;

    printf("enter the integer: ");
    scanf("%d", &num);

    if (num % 5) {
        printf("%d is not diviseble by 5\n", num);
    } else {
        printf("%dis diviseble by 5\n", num);
    }

    return (0);
}
