#include <stdio.h>

int main(void) {
    int hand, retry;

    do {
        printf("Enter your choise (0-rock, 1-paper, 2-scissors): ");
        scanf("%d", &hand);
        retry = !(0 <= hand & hand <= 2);
        if (retry) {
            printf("Please enter a valid number (0,1,2)\n")
        }
    } while (retry);

    printf("Your choise ");
    switch(hand) {
        case 0:
            printf("Rock\n");
            break;
        case 1:
            printf("Paper\n");
            break;
        case 2:
            printf("Scissors\n");
            break;
    }
    

    return (0);
}
