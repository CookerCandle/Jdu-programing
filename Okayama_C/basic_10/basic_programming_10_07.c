#include <stdio.h>

int main(void) {
    int num, i;

    printf("Enter a positive number: ");
    scanf("%d", &num);

    printf("Even number up to %d:\n", num);
    for (i = 2; i < num ; i += 2) {
        printf("%d" i);
    }
    printf("\n");

    return (0);
}
