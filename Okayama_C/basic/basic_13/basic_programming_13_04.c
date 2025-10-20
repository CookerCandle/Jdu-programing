#include <stdio.h>

int main(void) {
    int scores[5];
    int sum = 0;
    double avarage;

    printf("Enter score for student 1: ");
    scanf("%d", &scores[0]);
    printf("Enter score for student 2: ");
    scanf("%d", &scores[1]);
    printf("Enter score for student 3: ");
    scanf("%d", &scores[2]);
    printf("Enter score for student 4: ");
    scanf("%d", &score[3]);
    printf("Enter score for student 5: ");
    scanf("%d", &score[4]);

    sum = scores[0] + scores[1] + scores[2] + scores[3] + scores[4];
    
    avarage = (double)sum / 5.0;

    printf("Total sum %d\n", sum);  
    printf("Avarage %.1f\n", avarage);  

    return (0);
}
