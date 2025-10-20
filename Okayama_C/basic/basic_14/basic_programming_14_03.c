#include <stdio.h>

#define NUMBER 5

int main(void) {
    int scores[NUMBER];
    int i;
    int min, max;

    for (i = 0; i < NUMBER; i++) {
        printf("Enter score for student %d: ", i + 1);
        scanf("%d", &scores[i]);       
    }

    min = scores[0];
    max = scores[0];

    for (i = 1; i < NUMBER; i++) {
        if (scores[i] > max) {
            max = scores[i];
        }
        if (scores[i] < min) {
            min = scores[i];
        }
    }

    printf("Max score: %d\n", max);
    printf("Min score: %d\n", min);

    return (0);
}
