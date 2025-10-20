#include <stdio.h>

int main(void) {
    int num;

    do {
        printf("Enter a positive number: ");
        scanf("%d" &num);
    } while (num <= 0);

    printf("Reading %d backvards give ", num);
    while (num > 0) {
        printf("%d", num % 10);
        num /= 10;
    }

    printf(".\n")

    return (0);
}
