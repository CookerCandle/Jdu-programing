#include <stdio.h>

#define STUDENTS 4
#define SUBJECTS 3 

int main(void) {
    int i, j;
    int scores1[STUDENTS][SUBJECTS] = {
        {91, 72, 85},
        {68, 93, 78},
        {82, 86, 90},
        {75, 80, 85}
    };
    int scores2[STUDENTS][SUBJECTS] = {
        {91, 73, 85},
        {67, 93, 98},
        {82, 86, 90},
        {75, 70, 85}       
    };
    int sum[STUDENTS][SUBJECTS];

    printf("--- Test 1 Scores ---");
    for (i = 0; i < STUDENTS; i++) {
        for (j = 0; j < SUBJECTS; j++) {
            printf("%4d", scores1[i][j]);
        }
        printf("\n");
    }

    printf("--- Test 2 Scores ---");
    for (i = 0; i < STUDENTS; i++) {
        for (j = 0; j < SUBJECTS; j++) {
            printf("%4d", scores2[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < STUDENTS; i++) {
        for (j = 0; j < SUBJECTS; j++) {
            sum[i][j] = scores1[i][j] + scores2[i][j];
        }
    } 

    printf("\n--- Total scores ---\n");
    for (i = 0; i < STUDENTS; i++) {
        for (j = 0; j < SUBJECTS; j++) {
            printf("%4d", sum[i][j]);
        }
        printf("\n");
    }     

    return (0);
}
