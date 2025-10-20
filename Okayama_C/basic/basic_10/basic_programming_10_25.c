#include <stdio.h>

int main(void) {
    int num ;

    do {
        printf("Enter a number between 0 and 100: ");
        scanf("%d", &num);
    } while (num < 0 || num > 100);

    printf("You entered a valid number: %d\n", num);

    return (0);
}
