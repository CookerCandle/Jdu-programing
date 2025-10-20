#include <stdio.h>

int main(void) {
    printf("%d\n", 6 / 2 * 1 + 2);
    printf("%d\n", 6 / 2 * (1 + 2));
    printf("%d\n", 6 / (2 * (1 + 2)));
    
    return (0);
}