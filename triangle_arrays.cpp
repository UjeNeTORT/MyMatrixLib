#include <assert.h>
#include <stdio.h>

#include "matrix.h"
#include "triangle_arrays.h"
#include "userInterface.h"

static int ProgressionSum(int el_num);

// UNFINISHED
int PrintTriangle(FILE *stream, double *tr, int cathet) {
    assert (tr);
    assert (cathet);

    for (int row = 0; row < cathet; row++, fprintf(stream, "\n"))
        for (int col = 0; col <= row; col++)
            fprintf(stream, "%lg ", *(double *)(tr + ProgressionSum(row) + col));

    return 0;
}

static int ProgressionSum(int el_num) {
    return (el_num + 1) * el_num / 2;
}

int PrintMatrOnly(FILE *stream, double *mtx) {
    assert (mtx);

    int size_y = *mtx++;
    int size_x = *mtx++;

    struct matrix mtx_temp = {mtx, size_y, size_x};

    int ret = PrintMatrix(&mtx_temp, stream);

    return ret;
}
