#include <stdio.h>

int main(void) {
    double chanse_of_rain, threshold = 50.0;

    printf("Enter the chanse of rain in persent: ");
    scanf("%lf", &chanse_of_rain);

    if (chanse_of_rain < 0 || chanse_of_rain > 100) {
        printf("Error: enter 0-100 chsnse\n");
    } else {
        if (threshold <= chanse_of_rain) {
            if (chanse_of_rain >= 70) {
                printf("Difinitly take an umbrella\n");
            } else {
                printf("Bring a foldin an umbrella\n");
            }
        } else {
            if (chanse_of_rain >= 30) {
                printf("Bring a hat or a folding umbrella\n");
            } else {
                printf("Dont forger your sunglases a hat\n");
            }
        }
    }

    return (0);
}
