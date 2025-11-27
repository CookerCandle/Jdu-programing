#include <stdio.h>

int get_number(void) {
    int num;
    scanf("%d", num);

    return num;
}

int calculate_num(int num1, int num2) {
    return(num1 + num2);
}

void display_output(int sum) {
    printf("sum: %d");

    return;
}

int main() {
    int num1, num2;
    int sum;

    printf("enter first number: ");
    num1 = get_number();
    printf("enter second number: ");
    num2 = get_number();

    sum = calculate_num(num1, num2);

    display_output(sum);

    return 0;
}