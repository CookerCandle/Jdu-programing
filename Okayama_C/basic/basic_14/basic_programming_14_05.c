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

    min = max = scores[0];

    return (0);
}
