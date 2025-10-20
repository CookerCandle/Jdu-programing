#include <stdio.h>

int main(void) {
    int x, a, b;
    double dx;

    printf("(x = 1.123): %d\n", x = 1.123);
    printf("x: %d\n", x);

    printf("(dx = 1.123): %f\n", dx = 1.123);
    printf("dx: %f\n", dx);
    
    printf("a = b = 7 ... \n");
    a = b = 7;
    printf("a: %d,  b: %d\n", a,  b);

    return (0);
}
