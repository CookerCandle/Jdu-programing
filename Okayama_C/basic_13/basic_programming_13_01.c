#include <stdio.h>

int main(void) {
    int score1, score2, score3, score4, score5;
    int sum = 0;
    double avarage;

    printf("Enter score for student 1: ");
    scanf("%d", &score1);
    printf("Enter score for student 2: ");
    scanf("%d", &score2);
    printf("Enter score for student 3: ");
    scanf("%d", &score3);
    printf("Enter score for student 4: ");
    scanf("%d", &score4);
    printf("Enter score for student 5: ");
    scanf("%d", &score5);

    sum = score1 + score2 + score3 + score4 + score5;
    
    avarage = (double)sum / 5.0;

    printf("Total sum %d\n", sum);  
    printf("Avarage %.1f\n", avarage);  

    return (0);
}
