#include <stdio.h>

int main(void) {
    int i;
    int scores[5];

    // ERROR
    scores =  = {3, 5, 1, 2, 4};

    for (i = 0; i < 5; i++) {
        printf("scores[%d] = %d\n", i, scores[i]);
    }

    return (0);
}
