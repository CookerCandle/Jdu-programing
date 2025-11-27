#include <stdio.h>

void modify_value(int num) {
    printf("inside function %d\n", num);
    num = num * 2;
    printf("inside function %d\n", num);
}


int main(void) {
    int x = 10;
    printf("inside main\n");
    modify_value(x);
    printf("inside main\n");
    
    return 0;
}