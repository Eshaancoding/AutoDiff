#include "Matrix.hpp"
#include "Vector.hpp"

// ============================================================
//                      Helper functions!
// ============================================================

Matrix copy_contents_mat (const Matrix &l) {
    Matrix new_vec = Matrix(l.width, l.height);
    return new_vec;
}

// ============================================================
//                         ASSIGN
// ============================================================
Vector& Matrix::operator[] (int x) {
    return this->array[x];
}


