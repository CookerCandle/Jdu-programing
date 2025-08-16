#include <stdio.h>

int main(void) {
    int score:

    do {
        printf("Enter score: ");
        scanf("%d", &score);
        if (score < 0 || score > 100) {
            printf("score must be between 0 and 100\n");
        }
    } while (!(0 <= score && score <= 100));

    if (score >= 90) {
        printf("Grade: S\n");
    } else if (score >= 80) {
        printf("Grade: A\n");
    } else if (score >= 70) {
        printf("Grade: B\n");
    } else if (score >= 60) {
        printf("Grade: C\n");
    } else {
        printf("Grade: D\n");
    }


    return (0);
}
