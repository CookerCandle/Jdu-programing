#include <stdio.h>

int main(void) {
    int vx, vy;
    double dx, dy;

    printf("Enter two numbers (dx, dy): ");
    scanf("%lf %lf", &dx, &dy);

    vx = dx;
    vy = dy;

    printf("vx: %d\nvy: %d\n", vx, vy);
    printf("dx: %lf\ndy: %lf\n", dx, dy);
    printf("vx / vy = %d\n", vx / vy);
    printf("dx / dy = %lf\n", dx / dy);


    return (0);
}
