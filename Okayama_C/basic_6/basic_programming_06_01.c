#include <stdio.h>

int main(void) {
    double chanse_of_rain, threshold = 50.0;

    printf("Enter chanse of rain in persent: ");
    scanf("%lf", &chanse_of_rain);

    if (threshold <= chanse_of_rain) {
        printf("Its likely rain, bring the umbrella\n");
    } else {
        printf("The weather looks fine, bring a hat\n");
    }

    return (0);
}
