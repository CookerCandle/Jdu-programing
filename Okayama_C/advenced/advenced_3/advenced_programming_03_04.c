#include <stdio.h>

int global_var = 100;

void my_function(void) {
    int local_var = 20;
    printf("in my function\n");
    printf("local_var = %d\n", local_var);
    printf("global_var = %d\n", global_var);
}


int main(void) {
    int local_var = 10;
    printf("in main\n");
    printf("local_var = %d\n", local_var);
    printf("global_var = %d\n", global_var);

    my_function();

    printf("after my_function\n");
    printf("local_var = %d\n", local_var);
    printf("global_var = %d\n", global_var);
    
    return 0;
}