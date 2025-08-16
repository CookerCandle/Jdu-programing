#include <stdio.h>

int main(void) {
    int num;
    in continue_flag;

    do {
        printf("Enter a integer: ");
        scanf("%d", &num);

        if (num % 2 == 0) {
            printf("%d is even\n", num);
        } else {
            printf("%d is odd\n", num);
        }

        printf("Continue? (1 yor yes, 0 for no): ");
        scanf("%d", &continue_flag);
    } while (continue_flag == 1);

    return (0);
}
