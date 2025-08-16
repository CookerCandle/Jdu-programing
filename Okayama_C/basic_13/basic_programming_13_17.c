#include <stdio.h>

int main(void) {
    int a = 3, b = 5, tmp;

    printf("a: %d, b: %d\n", a, b);

    tmp = a;
    a = b;
    b = tmp;

    printf("a: %d, b: %d\n", a, b);

    return (0);
}
