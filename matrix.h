#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int** data;
    int rows;
    int cols;
} Matrix;

Matrix* create_matrix(int rows, int cols);
void free_matrix(Matrix* mat);
int determinant(Matrix* mat);

#endif