#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int random_num, random_num_1_100;

    srand((unsigned int)time(NULL));
    
    random_num = rand();
    printf("random number: %d\n", random_num);

    random_num_1_100 = (rand() % 100) + 1;
    printf("random number 1-100: %d\n", random_num_1_100);
    
    return 0;
}