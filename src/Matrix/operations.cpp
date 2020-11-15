#include "Matrix.hpp"
#include "Vector.hpp"
#include "Variable.hpp"

// ============================================================
//                      Helper functions!
// ============================================================

Matrix copy_contents_mat (const Matrix &l) {
    Matrix new_vec = Matrix(l.width, l.height);
    return new_vec;
}

// ============================================================
//                       ASSIGN/ACCESS
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


// ============================================================
//                         ADDITION
// ============================================================

Matrix operator+ (const Matrix &a, const Matrix &b) {
    // see if width / height is feasible
    if (a.width != b.width) throw invalid_argument("Width invalid");
    if (a.height != b.height) throw invalid_argument("Height invalid");
    // create matrix 
    Matrix return_mat = Matrix(a.height, a.width);
    // operations
    for (int i = 0; i < a.height; i++) {
        for (int x = 0; x < a.width; x++) {
            return_mat.array[i].array[x] = a.array[i].array[x] + b.array[i].array[x];
        }
    }
    // return
    return return_mat;
}

Matrix operator+ (const Matrix &a, const double &b) {
    // create matrix 
    Matrix return_mat = Matrix(a.height, a.width);
    // operations
    for (int i = 0; i < a.height; i++) {
        for (int x = 0; x < a.width; x++) {
            Variable *new_var = new Variable();
            new_var->operation = op::argument;
            new_var->value = b;
            return_mat.array[i].array[x] = a.array[i].array[x] + (*new_var);
        }
    }
    // return
    return return_mat;
}


Matrix operator+ (const double &b, const Matrix &a) {
    // create matrix 
    Matrix return_mat = Matrix(a.height, a.width);
    // operations
    for (int i = 0; i < a.height; i++) {
        for (int x = 0; x < a.width; x++) {
            Variable *new_var = new Variable();
            new_var->operation = op::argument;
            new_var->value = b;
            return_mat.array[i].array[x] = *(new_var) + a.array[i].array[x];
        }
    }
    // return
    return return_mat;
}


// ============================================================
//                       SUBTRACTION
// ============================================================

Matrix operator- (const Matrix &a, const Matrix &b) {
    // see if width / height is feasible
    if (a.width != b.width) throw invalid_argument("Width invalid");
    if (a.height != b.height) throw invalid_argument("Height invalid");
    // create matrix 
    Matrix return_mat = Matrix(a.height, a.width);
    // operations
    for (int i = 0; i < a.height; i++) {
        for (int x = 0; x < a.width; x++) {
            return_mat.array[i].array[x] = a.array[i].array[x] - b.array[i].array[x];
        }
    }
    // return
    return return_mat;
}


Matrix operator- (const Matrix &a, const double &b) {
    // create matrix 
    Matrix return_mat = Matrix(a.height, a.width);
    // operations
    for (int i = 0; i < a.height; i++) {
        for (int x = 0; x < a.width; x++) {
            Variable *new_var = new Variable();
            new_var->operation = op::argument;
            new_var->value = b;
            return_mat.array[i].array[x] = a.array[i].array[x] - *new_var;
        }
    }
    // return
    return return_mat;
}


Matrix operator- (const double &b, const Matrix &a) {
    // create matrix 
    Matrix return_mat = Matrix(a.height, a.width);
    // operations
    for (int i = 0; i < a.height; i++) {
        for (int x = 0; x < a.width; x++) {
            Variable *new_var = new Variable();
            new_var->operation = op::argument;
            new_var->value = b;
            return_mat.array[i].array[x] = *new_var - a.array[i].array[x];
        }
    }
    // return
    return return_mat;
}


// ============================================================
//                       MULTIPLICATION
// ============================================================

Matrix operator* (const Matrix &a, const Matrix &b) {
    // see if width / height is feasible
    if (a.width != b.width) throw invalid_argument("Width invalid");
    if (a.height != b.height) throw invalid_argument("Height invalid");
    // create matrix 
    Matrix return_mat = Matrix(a.height, a.width);
    // operations
    for (int i = 0; i < a.height; i++) {
        for (int x = 0; x < a.width; x++) {
            return_mat.array[i].array[x] = a.array[i].array[x] * b.array[i].array[x];
        }
    }
    // return
    return return_mat;
}


Matrix operator* (const Matrix &a, const double &b) {
    // create matrix 
    Matrix return_mat = Matrix(a.height, a.width);
    // operations
    for (int i = 0; i < a.height; i++) {
        for (int x = 0; x < a.width; x++) {
            Variable *new_var = new Variable();
            new_var->operation = op::argument;
            new_var->value = b;
            return_mat.array[i].array[x] = a.array[i].array[x] * *new_var;
        }
    }
    // return
    return return_mat;
}


Matrix operator* (const double &b, const Matrix &a) {
    // create matrix 
    Matrix return_mat = Matrix(a.height, a.width);
    // operations
    for (int i = 0; i < a.height; i++) {
        for (int x = 0; x < a.width; x++) {
            Variable *new_var = new Variable();
            new_var->operation = op::argument;
            new_var->value = b;
            return_mat.array[i].array[x] = *new_var * a.array[i].array[x];
        }
    }
    // return
    return return_mat;
}


// ============================================================
//                       DIVISION
// ============================================================

Matrix operator/ (const Matrix &a, const Matrix &b) {
    // see if width / height is feasible
    if (a.width != b.width) throw invalid_argument("Width invalid");
    if (a.height != b.height) throw invalid_argument("Height invalid");
    // create matrix 
    Matrix return_mat = Matrix(a.height, a.width);
    // operations
    for (int i = 0; i < a.height; i++) {
        for (int x = 0; x < a.width; x++) {
            return_mat.array[i].array[x] = a.array[i].array[x] / b.array[i].array[x];
        }
    }
    // return
    return return_mat;
}


Matrix operator/ (const Matrix &a, const double &b) {
    // create matrix 
    Matrix return_mat = Matrix(a.height, a.width);
    // operations
    for (int i = 0; i < a.height; i++) {
        for (int x = 0; x < a.width; x++) {
            Variable *new_var = new Variable();
            new_var->operation = op::argument;
            new_var->value = b;
            return_mat.array[i].array[x] = a.array[i].array[x] / *(new_var);
        }
    }
    // return
    return return_mat;
}


Matrix operator/ (const double &b, const Matrix &a) {
    // create matrix 
    Matrix return_mat = Matrix(a.height, a.width);
    // operations
    for (int i = 0; i < a.height; i++) {
        for (int x = 0; x < a.width; x++) {
            Variable *new_var = new Variable();
            new_var->operation = op::argument;
            new_var->value = b;
            return_mat.array[i].array[x] = *(new_var) / a.array[i].array[x];
        }
    }
    // return
    return return_mat;
}
