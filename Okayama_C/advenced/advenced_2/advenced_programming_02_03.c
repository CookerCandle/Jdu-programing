#include <stdio.h>

int main(void) {
    char str1[] = 'Hello';
    printf("Pattern 1: %s\n", str1);
    
    char str2[10] = 'World';
    printf("Pattern 2: %s\n", str2);
    
    char str3[] = {'C', 'o', 'd', 'e', '\0'};
    printf("Pattern 3: %s\n", str3);
    
    char str4[7] = {'P', 'r', 'o', 'g', '\0'};
    printf("Pattern 4: %s\n", str4);
    
    printf('\n');

    // ----------------
    char fruits[][10] = {"Apple", "Banana", "Cherry"};
    printf("Element 0 %s\n", fruits[0]);
    printf("Element 1 %s\n", fruits[1]);
    printf("Element 2 %s\n", fruits[2]);

    printf("Char of element 1: %c\n", fruits[1][0]);
    printf("Char of element 2: %c\n", fruits[2][2]);

    return (0);
}
