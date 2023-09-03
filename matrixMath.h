#include "matrix.h"

/**
 * multiplies two matrixes, if their sizes dont allow multiplication, says so and returns null
 *
 * @param [in] A first matrix
 * @param [in] B second matrix
 *
 * @return NULL if sizes of matrixes dont allow multiplication
 * @return pointer to a new matrix - result of multiplication
*/
struct matrix *MultMatrMatr(const struct matrix *A, const struct matrix *B);

/**
 * finds inverse matrix for matrix given
 * accepts only quadratic matrixes of size 2 or bigger
 *
 * @param [in] A matrix given
 *
 * @return NULL if matrix given is not quadratic
 * @return NULL if matrix given has determinant == 0 (thus having infinite solutions)
 * @return pointer to an inversed matrix
*/
struct matrix *GetInverseMatrix(const struct matrix *A);

/**
 * transposes matrix given
 *
 * @param [in] A matrix given
 *
 * @return pointer to a transposed matrix
*/
struct matrix *TransposeMatrix(const struct matrix *A);

/**
 * calculates matrix determinant
 *
 * @param [in] A matix given
 *
 * @return determinant of matrix given
*/
double DetMatrix(const struct matrix *A);

/**
 * finds additional minor to a matrix given
 *
 * @param [in] A matrix given
 * @param [in] elRow row which is to be crossed out to get minor
 * @param [in] elCol col which is to be crossed out to get minor
 *
 * @return pointer to an addittional minor
*/
struct matrix *GetAdditMinor (const struct matrix *A, int elRow, int elCol);

