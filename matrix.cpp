#include <assert.h>
#include <stdlib.h>

#include "matrix.h"

struct matrix *CreateMatrix(const int rowsNum, const int colsNum) {
    assert (rowsNum > 0);
    assert (colsNum > 0);

    struct matrix *res = (struct matrix *) calloc(1, sizeof(struct matrix));

    if (res == NULL)
        return NULL;

    res->rowsNum = rowsNum;
    res->colsNum = colsNum;

    int area = rowsNum*colsNum; // worth it?

    res->mtx = (double *) calloc(area, sizeof(double));

    return res;
}

double *GetMatrEl(const struct matrix *matrix, const int row, const int col) {
    assert (matrix);
    assert (matrix->mtx);
    assert (0 <= row && row < matrix->rowsNum);
    assert (0 <= col && col < matrix->colsNum);

    return (double *)(matrix->mtx + row * matrix->colsNum + col);
}

