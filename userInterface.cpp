#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "colors.h"
#include "matrix.h"
#include "userInterface.h"

// maybe i should make "stream" the first arg as it is in stdio.h funcs
int PrintMatrix(const struct matrix *matrix, FILE *stream) {
    assert (matrix);
    assert (matrix->mtx);
    assert (matrix->rowsNum > 0 && matrix->colsNum > 0);
    assert (stream);

    double currEl = NAN;

    for (int row = 0; row < matrix->rowsNum; row++) {
        for (int col = 0; col < matrix->colsNum; col++) {

            currEl = *GetMatrEl(matrix, row, col);

            assert (isfinite(currEl));

            if (isfinite(currEl)) {
                fprintf(stream, "%4.2lg ", currEl);
            }
            else {
                fprintf(stderr, RED("PrintMatrix: number is not finite\n"));
                return INF_EL;
            }

        }
        fprintf(stream, "\n");
    }

    return 0;
}

// bullshit
int ScanMatrix(struct matrix *matrix, FILE *stream) {
    assert (matrix);
    assert (matrix->mtx);
    assert (matrix->rowsNum > 0 && matrix->colsNum > 0);
    assert (stream);

    for (int row = 0; row < matrix->rowsNum; row++) {
        for (int col = 0; col < matrix->colsNum; col++) {

            if (scanf("%lg", matrix->mtx) == 1){
                matrix->mtx++;
            }
            else {
                fprintf(stderr, RED("ScanMatrix: error while scanning (last scanned: %lg )\n"), *matrix->mtx);
                return SCAN_NOT_MATCH;
            }

        }
    }

    return 0;
}
