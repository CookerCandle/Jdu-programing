#include <stdio.h>

void modify_array(int arr[]) {
    arr[0] = 100;
}

void print_array(int arr[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf(" %3d", arr[i]);
    }
    printf("\n");
}

int main() {
    int my_arr[3] = {10, 20, 30};

    printf("original array:");
    print_array(my_arr, 3);

    modify_array(my_arr);

    printf("modified array:");
    print_array(my_arr, 3);

    return 0;
}