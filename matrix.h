#pragma once

typedef struct {
    double* data;
    int rows;
    int cols;
} Matrix;

#define MAT_AT(mat, r, c) (mat)->data[(r) * (mat)->cols + c]
#define matPrint(m) matrixPrint(m, #m, 0);

Matrix* matrixCreate(int rows, int cols);
void matrixFree(Matrix* m);

void matrixFill(Matrix* m, double val);
void matrixPrint(Matrix* m, const char* name, int padding);

void matrixIdentity(Matrix* m);
char matrixIsIdentity(Matrix* m);

void matrixRand(Matrix* m, double low, double high);
void matrixAdd(Matrix* dest, const Matrix* a, const Matrix* b);
void matrixSub(Matrix* dest, const Matrix* a, const Matrix* b);
void matrixScalar(Matrix* a, double val);
void matrixMulti(Matrix* dest, const Matrix* a, const Matrix* b);
void matrixTranspose(Matrix* dest, const Matrix* a);
void matrixCopy(Matrix* dest, const Matrix* a);

void matrixShuffleRows(Matrix* m);
