#include <stdio.h>

int main(void) {
    double chanse_of_rain, threshold = 50.0;

    printf("Enter chanse of rain in percent: ");
    scanf("%lf", &chanse_of_rain);

    if (threshold <= chanse_of_rain) {
        if (chanse_of_rain  >= 70.0) {
            printf("Definetily bring an umbrella\n");
        } else {
            printf("Bring a folding umbrella\n");
        }   
    } else {
        if (chanse_of_rain >= 30.0) {
            printf("bring a hat or a umbrella\n")
        } else {
            printf("D'ont forget your sunglasses and a hat");
        }
    }

    return (0);
}
