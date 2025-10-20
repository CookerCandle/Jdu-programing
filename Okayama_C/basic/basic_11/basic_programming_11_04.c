#include <stdio.h>

int main(void) {
    int hand;

    do {
        printf("Enter your choise (0-rock, 1-paper, 2-scissors): ");
        scanf("%d", &hand);
    } while (!(0 <= hand && hand <= 2));

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
