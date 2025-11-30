#include <stdio.h>

char to_upper_char(char c){
    if (c >= 'a' && c <= 'z') {
        return (char) (c - 32);
    }

    return(c);
}

int is_alhabet(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return 1;
    }
    
    return 0;
}

int main() {
    char ch1 = 'A';
    char ch2 = 'B';
    char ch3 = '7';

    char upper_ch1 = to_upper_char(ch1);
    printf("'%c' to upper %c\n", ch1, upper_ch1);

    printf("'%c' is alhabet: %d\n",ch2, is_alhabet(ch2));
    printf("'%c' is alhabet: %d\n",ch3, is_alhabet(ch3));

    return 0;
}