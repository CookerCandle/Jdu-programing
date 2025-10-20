#include <stdio.h>

int main(void) {
    int option;

    printf("Menu options:\n");
    printf("1. Burger\n");
    printf("2. Drink\n");
    printf("3. Potato\n");
    printf("4. Pizza\n");
    printf("5. Salad\n");
    printf("Enter your choise (1-5): ");
    scanf("%d", &option);
    
    printf("You chouse ")
    switch (option) {
        case 1:
            printf("Burger\n");
            break;
        case 2:
            printf("Drink\n");
            break;
        case 3:
            printf("Potato\n");
            break;
        case 4:
            printf("Pizza\n");
            break;
        case 5:
            printf("Salad\n");
            break;
        default:
            printf("Invalid option, please Enter a number between 1 and 5\n");
            break;
    }

    return (0);
}
