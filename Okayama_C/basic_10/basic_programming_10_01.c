#include <stdio.h>

int main(void) {
    int num, i;

    printf("Enter the number: ");
    scanf("%d", &num);

    for (i = 0; i <= num; i++) {
        printf("%d", i);
    }
    printf("\n");

    return (0);
}
