#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "hello";
    size_t lenght = strlen(str);

    printf("lenght of string: %zu\n", lenght);

    return 0;
}