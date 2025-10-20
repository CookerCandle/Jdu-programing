#include <stdio.h>

int main(void) {
    double chanse_of_rain, threshold = 50.0;

    printf("Enter chanse of rain in persent: ");
    scanf("%lf", &chanse_of_rain);

    if (chanse_of_rain < 0) {
        printf("Please enter positive numbern\n");
    } else if (chanse_of_rain > 100) {
        printf("must not exceed 100 persent\n");
    } else {
        if (threshold <= chanse_of_rain) {
            if (chanse_of_rain >= 70) {
                printf("Difinitaly bring the umbrella\n")
            } else {
                printf("Bring a folding umbrella\n");
            }
        } else {
            if (chanse_of_rain >= 30) {
                printf("Bring a hat or a folding an umbrella\n");
            } else {
                printf("Dont forget your sunglasses and your hat\n")
            }
        }
    }

    return (0);
}
