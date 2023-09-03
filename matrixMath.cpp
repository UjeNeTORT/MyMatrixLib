#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "matrix.h"

const double EPS = 1e-6;

static int isEqual(const double a, const double b);

struct matrix *TransposeMatrix(const struct matrix *A) {
    assert (A);
    assert (A->mtx);
    assert (A->rowsNum > 0 && A->colsNum > 0);

    struct matrix *A_T = CreateMatrix(A->colsNum, A->rowsNum);

    assert (A_T); // TODO user friendly

    // TODO i m pretty sure there may be breeeeeeed down there (assert)
    for (int i = 0; i < A->rowsNum; i++)
        for (int j = 0; j < A->colsNum; j++)
            *GetMatrEl(A_T, j, i) = *GetMatrEl(A, i, j);

    return A_T;
}

struct matrix *GetAdditMinor (const struct matrix *A, int elRow, int elCol) {
    assert (A);
    assert (A->mtx);
    assert (0 <= elRow && elRow < A->rowsNum);
    assert (0 <= elCol && elCol < A->colsNum);

    if (A->rowsNum != A->colsNum) {
        fprintf(stdout, "GetAdditMinor: matrix must be quadratic\n");
        return NULL;
    }

    if (A->rowsNum == 1) {
        fprintf(stdout, "GetAdditMinor: matrix must be of size 2 or bigger\n");
        return NULL;
    }

    struct matrix *minor = CreateMatrix(A->rowsNum - 1, A->colsNum - 1);

    for (int row = 0; row < A->rowsNum; row++) {

        if (row == elRow) continue;

        for (int col = 0; col < A->colsNum; col++) {

            if (col == elCol) continue;

            if (row < elRow && col < elCol)
                *GetMatrEl(minor, row, col)         = *GetMatrEl(A, row, col);

            else if (row < elRow && col > elCol)
                *GetMatrEl(minor, row, col - 1)     = *GetMatrEl(A, row, col);

            else if (row > elRow && col < elCol)
                *GetMatrEl(minor, row - 1, col)     = *GetMatrEl(A, row, col);

            else if (row > elRow && col > elCol)
                *GetMatrEl(minor, row - 1, col - 1) = *GetMatrEl(A, row, col);

        }
    }

    return minor;
}

double DetMatrix(const struct matrix *A) {
    assert (A);
    assert (A->mtx);
    assert (A->colsNum > 0);
    assert (A->rowsNum > 0);

    if (A->rowsNum != A->colsNum){
        fprintf(stderr, "DetMatrix: only square matrix can have determinant\n");
        return NAN;
    }

    if (A->rowsNum == 1) return *GetMatrEl(A, 0, 0);

    double determinant = 0;
    int negative = 0;
    double localRes = 0;

    for (int col = 0; col < A->colsNum; col++, localRes = 0) { // играюс （＞人＜；）

        if (isEqual(*GetMatrEl(A, 0, col), 0)) continue;

        negative = (col % 2 == 1) ? 1 : 0;

        localRes += *GetMatrEl(A, 0, col) * DetMatrix(GetAdditMinor(A, 0, col));

        if (negative) localRes *= -1;

        determinant += localRes;

    }

    return determinant;
}

struct matrix *MultMatrMatr(const struct matrix *A, const struct matrix *B) {
    assert (A);
    assert (A->mtx);
    assert (A->rowsNum > 0 && A->colsNum > 0);
    assert (B);
    assert (B->mtx);
    assert (B->rowsNum > 0 && B->colsNum > 0);

    if (A->colsNum != B->rowsNum) {
        fprintf(stderr, "Unable to multiply matrixes A (%d x %d) and B (%d x %d) as %d != %d\n", A->rowsNum, A->rowsNum, B->rowsNum, B->colsNum, A->colsNum, B->rowsNum);
        return NULL;
    }

    struct matrix *C = CreateMatrix(A->rowsNum, B->colsNum);

    double local_sum = 0;

    for (int row = 0; row < C->rowsNum; row++) {

        for (int col = 0; col < C->colsNum; col++) {

            for (int cnt = 0; cnt < A->colsNum; cnt++) {

                local_sum += *GetMatrEl(A, row, cnt) *
                             *GetMatrEl(B, cnt, col);

            }

        *GetMatrEl(C, row, col) = local_sum;

        local_sum = 0;

        }

    }

    return C;
}

struct matrix *GetInverseMatrix(const struct matrix *A) {
    assert (A);
    assert (A->mtx);
    assert (A->rowsNum > 0 && A->colsNum > 0);

    if (A->rowsNum != A->colsNum){
        fprintf(stderr, "GetInverseMatrix: only square matrix allowed\n");
        return NULL;
    }

    struct matrix *inverseA = CreateMatrix(A->rowsNum, A->colsNum);

    double currEl = 0;

    double detA = DetMatrix(A);

    if (isEqual(detA, 0)) {
        fprintf(stdout, "GetInverseMatrix: determinant is equal to 0, infinite solutions\n");
        return NULL;
    }

    for (int row = 0; row < A->rowsNum; row++) {
        for (int col = 0; col < A->colsNum; col++) {

            currEl = DetMatrix(GetAdditMinor(A, col, row)) / detA;

            if ((col + row) % 2 == 1) currEl *= -1;

            if (isEqual(currEl, 0)) currEl = 0;

            *GetMatrEl(inverseA, row, col) = currEl;

        }
    }

    return inverseA;
}

static int isEqual(const double a, const double b) {
    assert (isfinite(a));
    assert (isfinite(b));

    return (fabs(a - b) < EPS);
}

