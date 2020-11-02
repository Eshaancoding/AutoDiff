#include "Matrix.hpp"

// ============================================================
//                      Helper functions!
// ============================================================

Matrix copy_contents_mat (const Matrix &l) {
    Matrix new_vec = Matrix(l.width, l.height);
    return new_vec;
}

// ============================================================
//                         ADDITION
// ============================================================

Matrix operator+ (const Matrix &a, const Matrix &b) {
    // check size
    if (a.width != b.width || a.height != b.height) {
        throw invalid_argument("adding matrix size invalid");
    }
    // make copy of matrix
    // do operations
    return Matrix(2,3); 
}

Matrix operator+ (const Matrix &a, const double &b) {
    return Matrix(2,3);
}

Matrix operator+ (const double &b, const Matrix &a) {
    return Matrix(2,3);
}

