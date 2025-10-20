#include <stdio.h>

int main(void) {
    int num, i;

    printf("Enter a positive number: ");
    scanf("%d", &num);

    for (i = num; i >= 0; i--) {
        printf("%d" i);
    }
    printf("\n");

    return (0);
}
