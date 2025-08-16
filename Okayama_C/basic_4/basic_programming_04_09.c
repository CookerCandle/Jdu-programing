#include <stdio.h>

int main(void) {
    int vx, vy, sum, product;

    printf("Enter two integers: ");
    scanf("%d %d\n", &vx, &vy);

    sum = vx + vy;
    product = vx * vy;

    printf("Sum = %d\n", sum); 
    printf("Product = %d\n", product); 

    return (0);
}
