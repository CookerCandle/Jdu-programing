#include <stdio.h>

int main(void) {
    int vx, vy;

    printf("enter two numbers (vx, vy): ");
    scanf("%d %d", &vx, &vy);

    printf("mean = %f\n", (vx + vy) / 2.0); 

    return (0);
}
