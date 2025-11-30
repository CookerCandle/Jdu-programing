#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, roll;
    srand((unsigned int)time(NULL));

    printf("dice roll:\n");
    for(i = 0; i < 5; i++) {
        roll = (rand() % 6) + 1;
        printf("roll %d: %d\n", (i + 1), roll);
    }
    
    return 0;
}