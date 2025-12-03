#include <stdio.h>

void reverse_array(int arr[], int size){
    int start = 0;
    int end = size - 1;
    int temp;

    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    
        start++;
        end--;
    }
}

void print_array(int arr[], int size) {
    int i;
    
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
    }
}

int main() {
    int my_data[] = {10, 20, 30, 40, 50};
    int arr_size = 5;

    printf("original array: ");
    print_array(my_data, arr_size);

    printf("reversed array: ");
    print_array(my_data, arr_size);

    return 0;
}