#include <stdio.h>

int pow2(int a) {
    int result;
    result = a * a;
    
    return (result);
}

int main() {
    int x = 10, y;
    y = pow2(x);
    printf("main: x = %d, y = %d\n", x, y);

    return 0;
}