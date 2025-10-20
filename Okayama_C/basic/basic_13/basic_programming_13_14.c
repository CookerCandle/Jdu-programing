#include <stdio.h>

int main(void) {
    int i;
    int squares[5];

    for(i = 0; i < 5; i++) {
        squares[i] = i * i;
    }

    for (i = 0; i < 5; i++) {
        printf("squares[%d] = %d\n", i, squares[i]);
    }

    return (0);
}
