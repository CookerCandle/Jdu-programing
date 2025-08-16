#include <stdio.h>

int main(void) {
    // NUmber of each coin
    printf("1 yen coin: %d piecesn\n", 5)
    printf("10 yen coin: %d piecesn\n", 4)
    printf("100 yen coin: %d piecesn\n", 6)

    // Calculate Total
    printf("Total: %d yen\n", 1 * 5 + 10 * 4 + 100 * 6);
    printf("Total: %d yen\n", (1 * 5) + (10 * 4) + (100 * 6));

    return (0);
}