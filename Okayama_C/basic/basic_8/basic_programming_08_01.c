#include <stdio.h>

int main(void) {
    int month:

    printf("Enter a month number: ");
    scanf("%d", &month);

    if (month >= 3 && month <= 5) {
        printf("%d is spring month\n", month);
    } else if (month >= 6 && month <= 8) {
        printf("%d is summer month\n", month);
    } else if (month >= 9 && month <= 11) {
        printf("%d is autum month\n", month);
    } else if (month == 1 || month == 2 || month == 12) {
        printf("%d is winter month\n", month);
    } else {
        printf("Error: month 1-12 must")
    }

    return (0);
}
