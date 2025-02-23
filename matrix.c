#include "matrix.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

Matrix* matrixCreate(int rows, int cols) {
    Matrix* m = malloc(sizeof(Matrix));
    m->rows = rows;
    m->cols = cols;
    m->data = malloc(sizeof(double) * rows * cols);
    return m;
}

void matrixFill(Matrix* m, double val) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d:%d\n", i, j);
            MAT_AT(m, i, j) = val;
        }
    }
}

void matrixIdentity(Matrix* m) {
    assert(m->cols != m->rows);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            MAT_AT(m, i, j) = (i == j) ? 1 : 0;
        }
    }
}

char matrixIsIdentity(Matrix* m) {
    if (m->cols != m->rows) {
        return 0;
    }
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            if (i == j) {
                if (MAT_AT(m, i, j) != 1) {
                    return 0;
                }
            } else {
                if (MAT_AT(m, i, j) != 0) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

void matrixFree(Matrix* m) {
    if (m->data) {
        free(m->data);
    }
    free(m);
}

void matrixPrint(Matrix* m, const char* name, int p) {
    printf("%*s%s = [\n", (int)p, "", name);
    for (int i = 0; i < m->rows; i++) {
        printf("%*s    ", (int)p, "");
        for (int j = 0; j < m->cols; j++) {
            printf("%f ", MAT_AT(m, i, j));
        }
        printf("\n");
    }
    printf("%*s]\n", (int)p, "");
}

void matrixRand(Matrix* m, double low, double high) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            MAT_AT(m, i, j) =
                ((float)rand() / (float)RAND_MAX) * (high - low) + low;
        }
    }
}

void matrixAdd(Matrix* dest, const Matrix* a, const Matrix* b) {
    assert(a->rows == b->rows && dest->rows == a->rows);
    assert(a->cols == b->cols && dest->cols == a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            MAT_AT(dest, i, j) = MAT_AT(a, i, j) + MAT_AT(b, i, j);
        }
    }
}

void matrixSub(Matrix* dest, const Matrix* a, const Matrix* b) {
    assert(a->rows == b->rows && dest->rows == a->rows);
    assert(a->cols == b->cols && dest->cols == a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            MAT_AT(dest, i, j) = MAT_AT(a, i, j) + (-1 * MAT_AT(b, i, j));
        }
    }
}

void matrixScalar(Matrix* a, double val) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            MAT_AT(a, i, j) *= val;
        }
    }
}

void matrixMulti(Matrix* dest, const Matrix* a, const Matrix* b) {
    assert(a->cols == b->rows && dest->rows == a->rows &&
           dest->cols == b->cols);
    int n = a->cols;
    for (int i = 0; i < dest->rows; i++) {
        for (int j = 0; j < dest->cols; j++) {
            for (int k = 0; k < n; k++) {
                MAT_AT(dest, i, j) += MAT_AT(a, i, k) * MAT_AT(b, k, j);
            }
        }
    }
}

void matrixTranspose(Matrix* dest, const Matrix* a) {
    assert(dest->cols == a->rows && dest->rows == a->cols);
    for (int i = 0; i < dest->rows; i++) {
        for (int j = 0; j < dest->cols; j++) {
            MAT_AT(dest, i, j) = MAT_AT(a, j, i);
        }
    }
}

void matrixCopy(Matrix* dest, const Matrix* a) {
    assert(dest->cols == a->cols && dest->rows == a->rows);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            MAT_AT(dest, i, j) = MAT_AT(a, i, j);
        }
    }
}

Matrix matRow(Matrix* m, int row) {
    return (Matrix){.rows = 1, .cols = m->cols, .data = &MAT_AT(m, row, 0)};
}

void matFunc(Matrix* m, double (*callbackFunc)(double d)) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            MAT_AT(m, i, j) = callbackFunc(MAT_AT(m, i, j));
        }
    }
}

void matrixShuffleRows(Matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        int randRow = (i + rand()) & (m->rows - i);
        for (int j = 0; j < m->cols; j++) {
            double save = MAT_AT(m, i, j);
            MAT_AT(m, i, j) = MAT_AT(m, randRow, j);
            MAT_AT(m, randRow, j) = save;
        }
    }
}

void matrixRowSwap(Matrix* m1, int row1, Matrix* m2, int row2) {
    double save = MAT_AT(m1, row1, row2);
    MAT_AT(m1, row1, row2) = MAT_AT(m2, row2, row1);
    MAT_AT(m2, row2, row1) = save;
}

void matrixRowScalar(Matrix* m, int row, double val) {
    for (int j = 0; j < m->cols; j++) {
        MAT_AT(m, row, j) *= val;
    }
}

void matrixRowAdd(Matrix* m1, int row1, const Matrix* m2, int row2) {
    assert(m1->rows == m2->rows && m1->cols == m2->cols);
    for (int j = 0; j < m1->cols; j++) {
        MAT_AT(m1, row1, j) += MAT_AT(m2, row2, j);
    }
}

Matrix* matrixRowAddDestCreate(const Matrix* m1, int row1, const Matrix* m2,
                               int row2) {
    assert(m1->rows == m2->rows && m1->cols == m2->cols);
    Matrix* dest = matrixCreate(1, m1->cols);
    for (int j = 0; j < m1->cols; j++) {
        MAT_AT(dest, 0, j) = MAT_AT(m1, row1, j) + MAT_AT(m2, row2, j);
    }
    return dest;
}

Matrix* matrixSubmatrixCreate(const Matrix* m, int* rowArrIdxs, int rowArrLen,
                           int* colArrIdxs, int colArrLen) {
    assert(m->rows > rowArrLen && m->cols > colArrLen);
    Matrix* dest = matrixCreate(m->rows - rowArrLen, m->cols - colArrLen);

    int ic = 0;
    int jc = 0;
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            char shouldAssign = 1;
            for (int ia = 0; ia < rowArrLen; ia++) {
                if (i == rowArrIdxs[ia]) {
                    shouldAssign = 0;
                }
            }
            if (!shouldAssign) {
                continue;
            }
            for (int ja = 0; ja < colArrLen; ja++) {
                if (j == colArrIdxs[ja]) {
                    shouldAssign = 0;
                }
            }
            if (shouldAssign) {
                // TODO: For some reason you need to flip jc and ic for it to work. I don't understand why. Look into this
                MAT_AT(dest, jc, ic) = MAT_AT(m, i, j);
                ic++;
                if (ic >= m->rows - rowArrLen){
                    ic = 0;
                    jc++;
                }
            }
        }
    }

    return dest;
}
