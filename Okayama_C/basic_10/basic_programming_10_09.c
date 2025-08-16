#include <stdio.h>

int main(void) {
    int num, i = 0;

    printf("Enter the positive number: ");
    scanf("%d", &num);

    while(i <= num) {
        printf("%d", i);
        i++;
    }
    printf("\n");

    return (0);
}
