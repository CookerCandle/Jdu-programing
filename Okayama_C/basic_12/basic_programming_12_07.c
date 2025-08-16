#include <stdio.h>

int main(void) {
    int num, total = 0;

    printf("Enter integers:\n");

    while (1) {
        printf(">> ");
        scanf("%d", &num);

        if (num == 0) {
            printf("Non positive number entered (%d).\n", num);
            continue;
        }

        if (total > 100) {
            pritf("total exceeded 100 (%d).\n", total);
            break;
        }
    }

    printf("Final total: %d\n", total);

    return (0);
}
