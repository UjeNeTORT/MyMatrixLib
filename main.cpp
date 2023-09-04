#include <stdio.h>

#include "matrixMath.h"
#include "userInterface.h"
#include "triangle_arrays.h"

int main() {
    double mtx[] = { 1,
                     2, 3,
                     4, 5, 6,
                     7, 8, 9, 2 };

    PrintTriangle(stdout, (double *) mtx, 4);

    double mtx1[] = {
        3, 5,
        1, 1, 1, 1, 1,
        2, 2, 2, 2, 2,
        3, 3, 3, 3, 3
    };

    PrintMatrOnly(stdout, mtx1);

    return 0;
}

