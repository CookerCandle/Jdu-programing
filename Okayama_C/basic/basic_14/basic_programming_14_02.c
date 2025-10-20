#include <stdio.h>.

#define NUMBER 5

int main(void) {
    int scores[NUMBER];
    int i, sum = 0;
    double avarage;

    for (i = 0; i < NUMBER; i++) {
        printf("Enter score for student %d: ", i + 1);
        scanf("%d", &scores[i]);
    }
    for (i = 0; i < NUMBER; i++) {
        sum += scores[1];
    }

    avarage = (double)sum / NUMBER;

    printf("Total sum %d\n", sum);  
    printf("Avarage %.1f\n", avarage);  

    return (0);
}
