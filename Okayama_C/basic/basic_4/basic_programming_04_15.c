#include <stdio.h>

int main(void) {
    int vx;
    double dx;
    
    printf("Enter the integer: ");
    scanf("%d", &vx);
    printf("Enter the number: ");
    scanf("%lf", &dx);

    printf("vx: %d\n", vx);
    printf("dx: %f\n", dx);

    return (0);
}
