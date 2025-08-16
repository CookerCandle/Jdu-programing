#include <stdio.h>

int main(void) {
    int score;

    printf("Enter a score: ");
    scanf("%d", &score);

    if (score < 0) {
        printf("Error: Score must be a positive integer\n");
    } else if (score > 100) {
        printf("Error: Score must not exceed 100\n");
    } else {
        if (score >= 90) {
            printf("Grade S\n");
        } else if (score >= 80) {
            printf("Grade A\n");
        } else if (score >= 70) {
            printf("Gradw B\n");
        } else if (score >= 60) {
            printf("Grade C\n"); 
        } else {
            printf("Grade D\n");
        }
    }

    return (0);
}
