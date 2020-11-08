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

void Matrix::operator= (initializer_list<initializer_list<double>> ar) {
    // find height / width
    int ar_height = ar.size();
    int ar_width = ar.begin()->size();
    for (int i = 1; i < ar_height; i++) {
        if (ar_width != (ar.begin()+i)->size()) {
            throw invalid_argument("array invalid");
        }
    }
    // check height / width
    if (this->height != ar_height) throw invalid_argument("height invalid. Expected " + to_string(this->height) + " got: " + to_string(ar_height));
    if (this->width != ar_width) throw invalid_argument("width invalid. Expected " + to_string(this->width) + " got: " + to_string(ar_width));
    // assign
    for (int i = 0; i < ar_height; i++) {
        this->array[i] = *(ar.begin() + i);
    }
}

void Matrix::operator= (initializer_list<initializer_list<Variable>> ar) {
    // find height / width
    int ar_height = ar.size();
    int ar_width = ar.begin()->size();
    for (int i = 1; i < ar_height; i++) {
        if (ar_width != (ar.begin()+i)->size()) {
            throw invalid_argument("array invalid");
        }
    }
    // check height / width
    if (this->height != ar_height) throw invalid_argument("height invalid");
    if (this->width != ar_width) throw invalid_argument("width invalid");
    // assign
    for (int i = 0; i < ar_height; i++) {
        this->array[i] = *(ar.begin() + i);
    }
}



