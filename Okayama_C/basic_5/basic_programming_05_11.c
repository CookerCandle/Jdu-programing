#include <stdio.h>

int main(void) {
    int total = 500, used, available;
    int threshold = 100;

    printf("Enter used capacity in GB: ");
    scanf("%d", &used)

    available = total - used
    if (available < threshold) 
        printf("Available capacity is bellow the threshold\n");
    printf("Only %d Gb left\n", available);
    

    return (0);
}
