#include <stdio.h>

int main(void) {
    char name[20];

    printf("Enter your name: ");
    scanf("%19s", name);

    printf("hello %s\n", name);

    return (0);
}
