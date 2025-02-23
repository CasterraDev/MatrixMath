#include "matrix.h"
#include <assert.h>
#include <stdio.h>

#define PROJECT_NAME "proj"

#define shift(xs, xs_sz) (assert(xs_sz > 0), --xs_sz, *xs++)

int testTranspose(void){
    Matrix* mat = matrixCreate(3, 3);
    Matrix* mat2 = matrixCreate(3, 3);
    MAT_AT(mat, 0, 0) = 1;
    MAT_AT(mat, 0, 1) = 2;
    MAT_AT(mat, 0, 2) = 3;
    MAT_AT(mat, 1, 0) = 4;
    MAT_AT(mat, 1, 1) = 5;
    MAT_AT(mat, 1, 2) = 6;
    MAT_AT(mat, 2, 0) = 7;
    MAT_AT(mat, 2, 1) = 8;
    MAT_AT(mat, 2, 2) = 9;
    matrixTranspose(mat2, mat);
    assert(MAT_AT(mat2, 0, 0) == 1);
    assert(MAT_AT(mat2, 0, 1) == 4);
    assert(MAT_AT(mat2, 0, 2) == 7);
    assert(MAT_AT(mat2, 1, 0) == 2);
    assert(MAT_AT(mat2, 1, 1) == 5);
    assert(MAT_AT(mat2, 1, 2) == 8);
    assert(MAT_AT(mat2, 2, 0) == 3);
    assert(MAT_AT(mat2, 2, 1) == 6);
    assert(MAT_AT(mat2, 2, 2) == 9);
    return 0;
}

int main(void) {
    printf("Starting Tests...\n");
    testTranspose();
    printf("Finished Tests\n");
    return 0;
}
