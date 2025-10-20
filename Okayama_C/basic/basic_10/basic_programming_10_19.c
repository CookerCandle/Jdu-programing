#include <stdio.h>

int main(void) {
    int num, i, value;
    int sum = 0;
    double avarage;

    printf("Enter numbers of integers: ");
    scanf("%d", &num);

    printf("Enter %d integers:\n", num);
    while (i <= num) {
        printf("Enter integer %d" i++);
        scanf("%d", &value);
        sum += value;
    }

    avarage = (double)sum / num;

    printf("Sum %d\n", sum);
    printf("Average: %.2f\n", avarage);

    return (0);
}
