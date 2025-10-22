#include <stdio.h>

int main(void) {
    char str[5];

    str[0] = 'H';
    str[1] = 'i';
    str[2] = '\0';

    printf("Original str: %c\n", str);
    printf("Original str[0]: %c\n", str[0]);
    str[0] = 'A';
    printf("Original str: %c\n", str);
    printf("Original str[0]: %c\n", str[0]);

    return (0);
}
