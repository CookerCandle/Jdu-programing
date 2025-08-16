#include <stdio.h>

int main(void) {
    printf("  | %2d %2d %2d %2d %2d\n", 1, 2, 3, 4, 5);
    printf("--+------\n");
    printf("%d | %2d %2d %2d %2d %2d\n", 1, 1, 2, 3, 4, 5);
    printf("%d | %2d %2d %2d %2d %2d\n", 2, 2, 4, 6, 8, 10);
    printf("%d | %2d %2d %2d %2d %2d\n", 3, 3, 6, 9, 12, 15);
    printf("%d | %2d %2d %2d %2d %2d\n", 4, 4, 8, 12, 16, 20);
    printf("%d | %2d %2d %2d %2d %2d\n", 5, 5, 10, 15, 20, 25);

    return (0);
}