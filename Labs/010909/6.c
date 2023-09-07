#include <stdio.h>

#define ROWS 3
#define COLS 4

int calc_transposed_matrix(int matrix[ROWS][COLS], int result[COLS][ROWS]);

int main() {
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int transposed_matrix[COLS][ROWS];

    calc_transposed_matrix(matrix, transposed_matrix);

    // printing result just to make sure
    for (int r=0; r<COLS; r++) {
        for (int c=0; c<ROWS; c++)
            printf("%d ", transposed_matrix[r][c]);
        printf("\n");
    }
    
    return 0;
}

int calc_transposed_matrix(int matrix[ROWS][COLS], int result[COLS][ROWS]) {
    for (int r=0; r<ROWS; r++) {
        for (int c=0; c<COLS; c++) {
            result[c][r] = matrix[r][c];
        }
    }
}