#include <stdio.h>

int main(void) {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    switch(num) {
        case 1:
            printf("Red\n");
            break;
        case 2:
            printf("Blue\n");
            break;
        case 3:
            printf("Green\n");  
    }

    return (0);
}
