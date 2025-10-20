#include <stdio.h>

int main(void) {
    int age, adult_age = 18;

    printf("Enter your age: ");
    scanf("%d", &age);

    if (age >= adult_age) {
        printf("You are an adult\n");
    }

    return (0);
}
