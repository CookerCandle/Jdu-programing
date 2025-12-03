#include <stdio.h>

double sum_double_array(double arr[], int size) {
    int i;
    double total = 0.0;

    for (i = 0; i < size; i++) {
        total += arr[i];
    }
    
    return total;
}

int main() {
    double my_arr[] = {10.0, 20.5, 30.0, 40.0, 50.5};
    int arr_size = 5;
    double result = sum_double_array(my_arr, arr_size);

    printf("sum of array elements: %f", result);
    
    return 0;
}