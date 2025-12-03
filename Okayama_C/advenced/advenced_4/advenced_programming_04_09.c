#include <stdio.h>

int is_white_space_char(char c){
    switch (c) {
    case ' ':
    case '\t':
    case '\n':
    case '\r':
    case '\f':
    case '\v':
        return 1;
    default:
        return 0;
    }
}

int my_strlen(char str[]) {
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }
    
    return len;
}

void trim_whitespace(char str[]) {
    int len = my_strlen(str);
    int start = 0;
    int end = len - 1;
    int i;

    while (is_white_space_char(str[start])) {
        start++;
    }

    while (end >= start && is_white_space_char(str[end])) {
        end--;
    }

    for (int i = start; i <= end; i++) {
        str[i - start] = '\0';
    }
}

int main() {
    char str1 = "  Hello World  ";
    char str2 = "\t\t trim me \n\n ";
    char str3 = "notrim";

    printf("original: \"%s\"\n", str1);
    trim_whitespace(str1);
    printf("trimed \"%s\"\n", str1);
    
    printf("original: \"%s\"\n", str2);
    trim_whitespace(str2);
    printf("trimed \"%s\"\n", str2);

    printf("original: \"%s\"\n", str3);
    trim_whitespace(str3);
    printf("trimed \"%s\"\n", str3);
    return 0;
}