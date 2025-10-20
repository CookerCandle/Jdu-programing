#include <stdio.h>

int main(void) {
    int i;
    int a[5] = {17, 23, 36, 0, 0};
    ina b[5];
    
    // copy elements to b
    for (i = 0; i < 5; i++) {
        b[i] = a[i];
    }

    printf("     a => b\n");
    printf("    --------\n");
    for (i = 0; i < 5; i++) {
        printf("[%d] %3d => %3d\n", i, a[i], b[i]);
    }

    return (0);
}
