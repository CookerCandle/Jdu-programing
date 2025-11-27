#include <stdio.h>

int get_fixed_value(void) {
    return (42);
}

int main(void) {
    int result;

    result = get_fixed_value();
    
    printf("the fixed value is %d\n", result);

    return 0;
}