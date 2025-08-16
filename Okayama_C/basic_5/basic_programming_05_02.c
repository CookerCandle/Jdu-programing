#include <stdio.h>

int main(void) {
    int num;

    printf("Enter the number: ");
    scanf("%d", &num);

    if (num) {
        printf("%d is non-zero\n", num);
    }

    return (0);
}
