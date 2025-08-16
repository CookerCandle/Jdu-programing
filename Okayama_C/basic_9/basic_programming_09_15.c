#include <stdio.h>

int main(void) {
    int year, month, day;
    int c, y, m, d, day_of_week;

    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month: ");
    scanf("%d", &month);
    printf("Enter day: ");
    scanf("%d", &day);

    c = year / 100;
    y = year % 100;
    m = month;

    // Zeller congruence alghorithm to findthe day of week

    if (month < 3) {
        m += 12;
        y--;
    }

    day_of_week =  
        (day + (13 * (m + 1) / 5) + y + (y / 4) + (c  / 4) - (2 * c )) % 7;

    switch (day_of_week) {
        case 0:
            printf("The day is Saturday\n");
            break
        case 1:
            printf("The day is Sunday\n");
            break
        case 2:
            printf("The day is Monday\n");
            break
        case 3:
            printf("The day is Tuesday\n");
            break
        case 4:
            printf("The day is Wednesday\n");
            break
        case 5:
            printf("The day is Thursday\n");
            break
        case 6:
            printf("The day is Friday\n");
            break
    }

    return (0);
}
