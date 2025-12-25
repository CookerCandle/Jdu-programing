#include <stdio.h>

int my_strlen(char str[]) {
    int len = 0;
    
    while(str[len] != '\0') {
        len++;
    }

    return len;
}

void replace_char(char str[], char old_char[], char new_char[]) {
    int i;
    int len = my_strlen(str);

    for(i = 0; i < len; i++) {
        if(str[i] == old_char) {
            str[i] = new_char;
        }
    }
}

int main() {
    char str1 = "hello world";
    char str2 = "programming";
    char str3 = "apple";

    printf("original: \"%s\"\n", str1);
    printf("replace 'l' with 'x'\n");
    replace_char(str1, 'l', 'x');
    printf("modified: \"%s\"\n", str1);

    printf("original: \"%s\"\n", str2);
    printf("replace 'g' with 'z'\n");
    replace_char(str2, 'g', 'z');
    printf("modified: \"%s\"\n", str2);

    printf("original: \"%s\"\n", str3);
    printf("replace 'p' with 'q'\n");
    replace_char(str3, 'p', 'q');
    printf("modified: \"%s\"\n", str3);



    return 0;
}
