#include <stdio.h>

int main(void) {
    int num, i;

    printf("Enter a positive number: ");
    scanf("%d", &num);

    i = num;
    do {
        printf("%d", i--);
    } while (i >= 0 );
    
    printf("\n");

    return (0);
}
