#include <stdio.h>

int main(void) {
    char text[] = " Hello World C ";
    int i = 0, word_count = 0;
    int in_word = 0;

    while(text[i] != '\0') {
        if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t') {
            in_word = 0;
        } else if (in_word == 0) {
            word_count++;
            in_word = 1;
        }
        i++;
    }

    printf("String: \" %s\"\n", text);
    printf("Word count: %d\n", word_count);

    return (0);
}
