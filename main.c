#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    Matrix* mat = create_matrix(rows, cols);

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat->data[i][j]);
        }
    }

    int det = determinant(mat);
    printf("Determinant of the matrix = %d\n", det);

    free_matrix(mat);

    return 0;
}