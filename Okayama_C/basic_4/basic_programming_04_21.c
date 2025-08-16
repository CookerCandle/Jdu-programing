#include <stdio.h>

int main(void) {
    int vx = 10, vy = 3;
    double dx = 10.0;

    printf("        vx / vy = %d\n", vx / vy);
    printf("        vx / vy = %f\n", dx / vy);
    printf("(double)vx / vy = %f\n", (double)vx / vy);


    return (0);
}
