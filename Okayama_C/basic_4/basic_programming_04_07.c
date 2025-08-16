#include <stdio.h>

int main(void) {
    int vx, vy;

    printf("vx: ");
    scanf("%d\n", &vx);
    printf("vy: ");
    scanf("%d\n", &vy);

    printf("Sum = %d\n", vx + vy); 
    printf("Product = %d\n", vx * vy); 

    return (0);
}
