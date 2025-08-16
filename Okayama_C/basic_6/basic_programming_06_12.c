#include <stdio.h>

int main(void) {
    int n = 15;

    printf(" %d    +    3   = %2d\n", n, n + 3);
    printf("           -3   = %2d\n", -3);
    printf(" %d    /    3   = %2d\n", n, n / 3);
    printf(" %d    /    3.0 = %4.1f\n", n, n / 3.0);
    printf("     (int)  3.0 = %2d\n", (int)3.0);
    printf("  (double)  3   = %4.1f\n", (double)3);
    printf(" %d    ==  15   = %2d\n", n, n == 15);
    printf("  5.0  <=  3.0  = %2d\n", 5.0, n <= 3.0);

    return (0);
}
