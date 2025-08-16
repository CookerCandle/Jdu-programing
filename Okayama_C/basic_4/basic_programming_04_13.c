#include <stdio.h>

int main(void) {
    int dx, dy;


    printf("Enter two integers: ");
    scanf("%lf %lf\n", &dx, &dy);

    printf("dx: %f\ndy: %f\n", dx, dy); 
    printf("vx / vy = %f\n", dx / dy); 

    return (0);
}
