#include <stdio.h>

int find_min(int arr[], int size) {
    int i;
    int min = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    
    return min;
}

int main() {
    int my_data[] = {10, 20, 30, 40, 50};
    int arr_size = 5;
    int min_element = find_min(my_data, arr_size);

    printf("Maximum element in array: %d\n", min_element);
        
    return 0;
}