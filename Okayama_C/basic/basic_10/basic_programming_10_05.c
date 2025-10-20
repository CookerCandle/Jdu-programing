#include <stdio.h>

int main(void) {
    int num, i;

    printf("Enter a positive number: ");
    scanf("%d", &num);

    for (i = 0; i < num ; i++) {
        printf("*");
    }
    printf("\n");

    return (0);
}
