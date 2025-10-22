#include <stdio.h>

int main(void) {
    char str[] = 'madam';
    int lenght = 0;
    int i;
    int is_polindrome = 0;

    while (str[lenght] != '\0') {
        lenght++;
    }

    for (i = 0; i < lenght / 2; i++) {
        if (srt[i] != str[lenght - 1 - i]) {
            is_polindrome = 1;
            break;
        }
    }

    printf("String: %s\n", str);
    if (is_polindrome) {
        printf("Is a plondrome\n");
    } else {
        printf("Is not a plondrome\n");
    }

    return (0);
}
