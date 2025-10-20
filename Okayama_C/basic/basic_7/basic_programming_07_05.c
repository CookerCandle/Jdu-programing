#include <stdio.h>

int main(void) {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num > 0) {
        printf("%d is a positive number\n", num);
    } else if (num == 0) {
        printf("%d is a zero\n", num);
    } else {
        printf("%d ia s negative number\n", num);
    }

    return (0);
}
