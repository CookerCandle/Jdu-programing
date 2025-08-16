#include <stdio.h>

int main(void) {
    int score;

    printf("Enter the score: ");
    scanf("%d", &score);

    if (score < 0 || score > 100) {
        printf("Error: Score must be between 0 and 100\n");
    } else {
        switch (score / 10) {
            case 10:
            case 9:
                printf("Grade S\n");
                break;
            case 8:
                printf("Grade A\n");
                break;
            case 7:
                printf("Grade B\n");
                break;
            case 6:
                printf("Greade C\n");
                break;
            default:
                printf("Greade D\n");
                break;
        }
    }

    return (0);
}
