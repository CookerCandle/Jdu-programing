#include <stdio.h>

int main(void) {
    char text[] = 'programming';
    char search_char = 'g';
    int i = 0;
    int found_index = -1;

    while (text[i] != '\0') {
        if (text[i] == search_char) {
            found_index = i;
            break;
        }
        i++;
    }

    if (found_index != -1) {
        printf("Character '%c' found [%d] \n", search_char, found_index);
    } else {
        printf("Character '%c' not found\n", search_char);
    }

    return (0);
}
