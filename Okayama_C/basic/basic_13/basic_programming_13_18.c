#include <stdio.h>

int main(void) {
    int i, tmp;
    int x[5] = {1, 2, 3, 4, 5};

    // reverse elmentes
    for (i = 0; i < 5 / 2; i++) {
        tmp = x[i];
        x[i] = x[5 - 1 - i];
        x[5 - 1 - i] = tmp;
    }

    printf("Reversed array:\n");
    for(i = 0; i < 5; i ++) {
        printf("x[%d] = %d\n", i, x[i]);
    }

    return (0);
}
