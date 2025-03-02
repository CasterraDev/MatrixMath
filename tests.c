#define MATRIX_IMPLEMENTATION
#include "matrix.h"
#include <assert.h>
#include <stdio.h>

void fillMatrixByCounting(Matrix* m) {
    double c = 0;
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            c++;
            MAT_AT(m, i, j) = c;
        }
    }
}

int testTranspose(void) {
    Matrix* mat = matrixCreate(3, 3);
    Matrix* mat2 = matrixCreate(3, 3);
    fillMatrixByCounting(mat);
    matrixPrint(mat, "Transpose Test", 0);
    matrixTranspose(mat2, mat);
    matrixPrint(mat2, "Transpose Result Matrix", 0);
    assert(MAT_AT(mat2, 0, 0) == 1);
    assert(MAT_AT(mat2, 0, 1) == 4);
    assert(MAT_AT(mat2, 0, 2) == 7);
    assert(MAT_AT(mat2, 1, 0) == 2);
    assert(MAT_AT(mat2, 1, 1) == 5);
    assert(MAT_AT(mat2, 1, 2) == 8);
    assert(MAT_AT(mat2, 2, 0) == 3);
    assert(MAT_AT(mat2, 2, 1) == 6);
    assert(MAT_AT(mat2, 2, 2) == 9);
    printf("Test Passed\n");
    return 0;
}

int testSubmat(void) {
    Matrix* mat = matrixCreate(3, 3);
    fillMatrixByCounting(mat);
    matrixPrint(mat, "Submatrix Test", 0);
    int ra[] = {1};
    int ca[] = {1};
    Matrix* dest = matrixSubmatrixCreate(mat, ra, 1, ca, 1);
    matrixPrint(dest, "Submatrix Result Matrix", 0);
    assert(MAT_AT(dest, 0, 0) == 1);
    assert(MAT_AT(dest, 0, 1) == 3);
    assert(MAT_AT(dest, 1, 0) == 7);
    assert(MAT_AT(dest, 1, 1) == 9);
    printf("Test Passed\n");
    return 0;
}

int main(void) {
    printf("Starting Tests...\n");
    testTranspose();
    testSubmat();
    printf("Finished Tests\n");
    return 0;
}
