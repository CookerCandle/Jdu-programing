#include <stdio.h>

int main(void) {
    int num, i = 0;

    printf("Enter a positive number: ");
    scanf("%d", &num);

    while (i < num) {
        printf("*");
        i++
    }
    printf("\n");

    return (0);
}
