#include <stdio.h>

int main(void) {
    int i;
    int scores[5] = {3, 5};

    for (i = 0; i < 5; i++) {
        printf("scores[%d] = %d\n", i, scores[i]);
    }

    return (0);
}
