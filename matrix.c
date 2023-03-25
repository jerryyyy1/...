#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix* create_matrix(int rows, int cols) {
    Matrix* mat = malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;

    mat->data = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = malloc(cols * sizeof(int));
    }

    return mat;
}

void free_matrix(Matrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}

int determinant(Matrix* mat) {
    if (mat->rows != mat->cols) {
        printf("Error: determinant can only be calculated for square matrices.\n");
        return 0;
    }

    if (mat->rows == 1) {
        return mat->data[0][0];
    }

    if (mat->rows == 2) {
        return (mat->data[0][0] * mat->data[1][1]) - (mat->data[0][1] * mat->data[1][0]);
    }

    int det = 0;
    for (int i = 0; i < mat->cols; i++) {
        Matrix* sub_mat = create_matrix(mat->rows - 1, mat->cols - 1);

        for (int j = 1; j < mat->rows; j++) {
            int sub_mat_col = 0;
            for (int k = 0; k < mat->cols; k++) {
                if (k != i) {
                    sub_mat->data[j - 1][sub_mat_col] = mat->data[j][k];
                    sub_mat_col++;
                }
            }
        }

        int sign = (i % 2 == 0) ? 1 : -1;
        int sub_det = determinant(sub_mat);
        det += sign * mat->data[0][i] * sub_det;

        free_matrix(sub_mat);
    }

    return det;
}