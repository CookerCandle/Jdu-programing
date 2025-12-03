#include <stdio.h>

int liner_search(int arr[], int size, int target) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

int main() {
    int my_data[] = {10, 20, 30, 40, 50};
    int arr_size = 5;
    int target1 = 30;
    int target2 = 90;

    int index1 = liner_search(my_data, arr_size, target1);
    if (index1 != -1) {
        printf("element %d found at index %d\n", target1, index1);
    } else {
        printf("element %d not found\n", target1);
    }

    int index2 = liner_search(my_data, arr_size, target2);
    if (index2 != -1) {
        printf("element %d found at index %d\n", target2, index2);
    } else {
        printf("element %d not found\n", target2);
    }
    
    return 0;
}