#include <stdio.h>

#define NUMBER 5

int main(void) {
    int i;
    int numbers[NUMBER] = {5, 2, 8, 3, 6};
    int odd_sum = 0;
    int even_sum = 0;

    for (i = 0; i < NUMBER; i++) {
        if (numbers[i] % 2 == 0) {
            even_sum += numbers[i];
        } else {
            odd_sum += numbers[i];
        }
    }

    printf("Sum of even numbers: %d\n", even_sum);
    printf("Sum of odd numbers: %d\n", odd__sum);

    return (0);
}
