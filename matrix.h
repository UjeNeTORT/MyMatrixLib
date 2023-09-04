#ifndef MATRIX_H
#define MATRIX_H

struct matrix {
    double *mtx;
    int rowsNum;
    int colsNum;
};

enum MatrixErrs {
    ALLOC_TROUBLES = 1
};

/**
 * allocate memory for new matrix (rowsNum x colsNum)
 * @param [in] rowsNum number of rows of new matrix
 * @param [in] colsNum number of cols of new matrix
*/
struct matrix *CreateMatrix(int rowsNum, int colsNum);

/**
 * get pointer to a matrix[row][col]
 * @param [in] matrix pointer to a matrix itself
 * @param [in] row row number
 * @param [in] col col number
*/
double *GetMatrEl(const struct matrix *matrix, const int row, const int col);

#endif // MATRIX_H
