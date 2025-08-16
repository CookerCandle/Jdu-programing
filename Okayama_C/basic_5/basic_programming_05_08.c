#include <stdio.h>

int main(void) {
    double chanse_of_rain, threshold = 50.0;

    printf("Enter chanse of rain (%): ");
    scanf("%lf", &chanse_of_rain);

    if (threshold <= chanse_of_rain) {
        printf("It's likely to rain, bring an umbrella\n");
    }

    return (0);
}
