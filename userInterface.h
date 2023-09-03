enum PrintMatrixErrs {
    INF_EL = 1
};

enum ScanMatrixErrs {
    SCAN_NOT_MATCH = 1
};



/**
 * prints matrix mtx (rows x cols) to a "stream"
*/
int PrintMatrix(const struct matrix *matrix, FILE *stream);

/**
 * scans matrix mtx (rows x cols) from a "stream"
 * memory for mtx has to be allocated manually outside the func
*/
int ScanMatrix(struct matrix *matrix, FILE *stream);
