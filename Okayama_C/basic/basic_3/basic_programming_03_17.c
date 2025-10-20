#include <stdio.h>

int main(void) {
    printf("%d seconds is", 90061);
    printf("%d days, ", 90061 / (60 * 60 *24));
    printf("%d hours, ", 90061 / (60 * 60) % 24);
    printf("%d minutes, ", 90061 / 60 % 60);
    printf("%d seconds. \n", 90061 % 60);

    return (0);
}