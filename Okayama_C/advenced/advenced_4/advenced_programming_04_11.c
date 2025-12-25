#include <stdio.h>

void print_matrix(int matrix[][3], int rows[]) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int my_matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    print_matrix(my_matrix, 2); 
    return 0;
}
