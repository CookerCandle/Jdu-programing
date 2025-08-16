#include <stdio.h>

#define NUMBER 10

int main(void) {
    int i;
    int scores[NUMBER] = {65, 70, 85, 60, 70, 90, 75, 80, 70, 100};
    int counts[11] = {0};

    for (i = 0; i < NUMBER; i++) {
        if (scores[i] >= 0 && scores[i] <= 100) {
            counts[scores[i] / 10]++;
        }
    }

    for (i = 0; i < 10; i++) {
        printf("%2d-%-2d: ", i * 10, i * 10 + 9);
        printf("%d\n", counts[i]);
    } 
    printf("  100: %d\n", counts[i])

    return (0);
}
