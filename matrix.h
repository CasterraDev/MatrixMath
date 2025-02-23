#pragma once

typedef struct {
    double* data;
    int rows;
    int cols;
} Matrix;

/**
 * QoL function to get access to an element without having to do math
 */
#define MAT_AT(mat, r, c) (mat)->data[(r) * (mat)->cols + c]

/**
 * QoL function to print a matrix just by giving the matrix
 */
#define matPrint(m) matrixPrint(m, #m, 0);

/**
 * Create and Return a matrix.
 * Calls Malloc MUST be freed (look at matrixFree)
 * @param rows amount of rows the matrix needs
 * @param cols amount of cols the matrix needs
 * @return The matrix with the requested rows/cols
 */
Matrix* matrixCreate(int rows, int cols);

/**
 * Frees a matrix
 * @param m The matrix to be freed
 */
void matrixFree(Matrix* m);


/**
 * Fills a matrix with `val`
 * @param m The matrix to be filled
 * @param val The value to fill the matrix with
 */
void matrixFill(Matrix* m, double val);

/**
 * Prints the matrix in a pretty way. Might want to look at matPrint for some QoL
 * @param m The matrix to be printed
 * @param name Name to use for the print
 * @param padding Amount of padding to use
 */
void matrixPrint(Matrix* m, const char* name, int padding);

/**
 * Makes a matrix into an identity matrix.
 * @param m The matrix to use. Needs to be a square matrix
 */
void matrixIdentity(Matrix* m);

/**
 * Sees if a matrix is an identity
 * @param m The matrix to look at
 * @return true if it is an identity; false if not
 */
char matrixIsIdentity(Matrix* m);

/**
 * Fills a matrix with random decimal values
 * @param m The matrix to use
 * @param low The low of the random values
 * @param high The high of the random values
 */
void matrixRand(Matrix* m, double low, double high);

/**
 * Adds two matrices together
 * @param dest The matrix where the result is stored
 * @param a The first matrix to use
 * @param b The second matrix to use
 */
void matrixAdd(Matrix* dest, const Matrix* a, const Matrix* b);

/**
 * Subtracts two matrices together
 * @param dest The matrix where the result is stored
 * @param a The first matrix to use
 * @param b The second matrix to use
 */
void matrixSub(Matrix* dest, const Matrix* a, const Matrix* b);

/**
 * Multiples an entire matrix by `val`
 * @param a The matrix to use
 * @param val The value to use
 */
void matrixScalar(Matrix* a, double val);

/**
 * Multiples two matrices together
 * @param dest The matrix where the result is stored
 * @param a The first matrix to use
 * @param b The second matrix to use
 */
void matrixMulti(Matrix* dest, const Matrix* a, const Matrix* b);

/**
 * Transposes a matrix
 * @param dest The matrix where the result is stored
 * @param a The matrix to use
 */
void matrixTranspose(Matrix* dest, const Matrix* a);

/**
 * Copies a matrix
 * @param dest The matrix where the result is stored
 * @param a The matrix to copy
 */
void matrixCopy(Matrix* dest, const Matrix* a);

/**
 * Shuffles the rows in a matrix.
 * @param a The matrix to shuffle
 */
void matrixShuffleRows(Matrix* m);
