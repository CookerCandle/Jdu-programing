#include <stdio.h>

int power(int base, int exp) {
    int result = 1;
    int i;

    for (i = 0; i < exp; i++) {
        result *= base; 
    }
    
    return base;
}

int max(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int num1 = 2;
    int num2 = 3;
    int num3 = 5;
    int p, m;

    p = power(num1, num2);
    printf("power(%d, %d) = %d", num1, num2, p);

    m = max(num1, num2);
    printf("max(%d %d) = %d", num1, num3, m);

    return 0;
}