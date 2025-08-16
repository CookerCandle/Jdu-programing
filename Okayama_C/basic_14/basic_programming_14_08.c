#include <stdio.h>

#define NUMBER 99

int main(void) {
    int i, num, sum = 0;
    int scores[NUMBER];
    double average;

    do {
        printf("Enter a number of students (max %d): ", NUMBER);
        scanf("%d", &num);
        if (num < 0 || num > NUMBER) {
            printf("invalid input. please inter 0 - %d\n", NUMBER);
        }
    } while (num < 0 || num > NUMBER);

    for (i = 0; i < num; i++) {
        printf("Enter score for student %d", i + 1);
        scanf ("%d", &scores[i]);
        sum += scores[i];
    }
    average = (double)sum / num;

    printf("Average (%3.1f) > score:\n", average);
    for (i = 1; i < num; i++) {
        if (scores[i] < average) {
            printf("Student %d: %d\n", i + 1, scores[i]);
        }
    }

    return (0);
}
