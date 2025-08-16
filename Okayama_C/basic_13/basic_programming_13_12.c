#include <stdio.h>

int main(void) {
    int i;
    int vx[5] = {0};
    double dx[5] = {0.0};
    
    for (i = 0; i < 5; i++) {
        printf("vx[%d] = %d\n", i, vx[i]);
        printf("dx[%d] = %.3f\n", i, dx[i]);
    }

    return (0);
}
