#include <stdio.h>

int main(void) {
    printf("20 / 7 = %d R %d\n", 20 / 7, 20 % 7);
    printf("-20 / -7 = %d R %d\n", -20 / -7, -20 % -7);
    printf("-20 / 7 = %d R %d\n", -20 / 7, -20 % 7);
    printf("20 / -7 = %d R %d\n", 20 / -7, 20 % -7);

    return 0;
}