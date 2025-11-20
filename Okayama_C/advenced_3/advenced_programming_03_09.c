#include <stdio.h>

int multiply_by_two(int num) {
    return num * 2;
}

int main(void) {
    int x = 5, result;

    result = multiply_by_two(x);

    printf("original value %d\n", x);
    printf("dubled value %d\n", result);

    return 0;
}