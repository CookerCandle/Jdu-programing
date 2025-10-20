#include <stdio.h>

int main(void) {
    int num, i;

    printf("Enter the positive number: ");
    scanf("%d", &num);

    i = num;
    while(i >= 0) {
        printf("%d", i);
        i--;
    }
    printf("\n");

    return (0);
}
