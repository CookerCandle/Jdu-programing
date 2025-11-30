#include <stdio.h>

int main() {
    int i, n;
    int factorial = 1;

    printf("enter a non negative integer: ");
    scanf("%d", &n);

    if(n < 0) {
        printf("factorial is not defined for negarive number\n");
    } else {
        for (i = 1; i <= n; i++) {
            factorial *= i; 
        }
        printf("factorial of %d: %d\n", n, factorial);
    }
    
    return 0;
}