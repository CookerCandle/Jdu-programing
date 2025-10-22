#include <stdio.h>

#define SIZE 128

int main(void) {
    char str[] = 'programming';
    int i;
    int frequency[SIZE] = {0};

    for (i = 0; str[i] != '\0'; i++) {
        frequency[(int)str[i]]++;
    }

    printf("String: %s\n", str);
    printf("Character frequency:\n");
    for (i = 0; i < SIZE; i++) {
        if (frequency[i] > 0) {
            printf("'%c': %d\n", (char)i, frequency[i]);
        }
    }

    return (0);
}
