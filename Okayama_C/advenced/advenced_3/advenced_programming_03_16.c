#include <stdio.h>

int calculate_factorial(int n) {
    int i, factorial = 1;

    for (i = 1; i <= n; i++) {
        factorial *= i; 
    }   

    return factorial;
}

int main() {
    int n, result;

    printf("enter a non negative integer: ");
    scanf("%d", &n);

    if(n < 0) {
        printf("factorial is not defined for negarive number\n");
    } else {
        result = calculate_factorial(n);
        printf("factorial of %d: %d\n", n, result);
    }

    return 0 ;
}