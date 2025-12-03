#include <stdio.h>

int find_max(int arr[], int size) {
    int i;
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    return max;
}

int main() {
    int my_data[] = {10, 20, 30, 40, 50};
    int arr_size = 5;
    int max_element = find_max(my_data, arr_size);

    printf("Maximum element in array: %d\n", max_element);
        
    return 0;
}