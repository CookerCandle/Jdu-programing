#include <stdio.h>

void function_c(void) {
    printf("inside function_c\n");
}

void function_b(void) {
    printf("inside function_b\n");
    function_c();
}

void function_a(void) {
    printf("inside function_a\n");
    function_b();
}

int main() {
    printf("starting main\n");
    function_a();
    printf("finishing main\n");
    
    return 0;
}
