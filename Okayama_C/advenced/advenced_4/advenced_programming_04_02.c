#include <stdio.h>

int sum_array_ptr(int *arr, int size) {
    int i, total = 0;

    for(i = 0; i < size; i++) {
        total += arr[i];
    }

    return total;
}

int main() {
    int my_data[] = {10, 20, 30, 40, 50};
    int arr_size = 5;
    int result = sum_array_ptr(my_data, arr_size);

    printf("sum: %d\n", result); 

    return 0;
}