#include <stdio.h>

int main(void) {
    int vx, vy, sum, product;

    printf("vx: ");
    scanf("%d\n", &vx);
    printf("vy: ");
    scanf("%d\n", &vy);

    sum = vx + vy;
    product = vx * vy;

    printf("Sum = %d\n", sum); 
    printf("Product = %d\n", product); 

    return (0);
}
