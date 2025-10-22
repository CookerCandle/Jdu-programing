#include <stdio.h>

int main(void) {
    char input_string[100];
    int lenght = 0;

    printf("Enter a string: ");
    scanf("%s", input_string);

    while (input_string[lenght] != '\0') {
        lenght++
    }

    printf("Lenght of the string: %d\n", lenght);

    return (0);
}
