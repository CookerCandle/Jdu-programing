#include <stdio.h>

int main(void) {
    int value;
    int sum = 0, count = 0, continue_flag;
    double avarage;

    do {
        printf("Enter an integer: ");
        scanf("%d", &value);
        sum += value;
        count++;

        printf("Continue? (1 for yes, 0 for no): ");
        scanf("%d", continue_flag);
    } while (continue_flag == 1);

    avarage = (double)sum / count;

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", avarage);

    return (0);
}
