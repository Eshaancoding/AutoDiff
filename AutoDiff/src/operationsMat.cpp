#include "coreMatrix.h"

Matrix::Matrix (const int height, const int width) {
    this->height = height;
    this->width = width;
    this->array = new Variable[this->height * this->width];
}

void Matrix::operator= (initializer_list<Variable> ar) {
    if (ar.size() != this->height * this->width) {
        throw invalid_argument("initalizing array invalid");
    }
    copy(ar.begin(), ar.end(), this->array);
}

void Matrix::operator= (initializer_list<double> ar) {
    if (ar.size() != this->height * this->width) {
        throw invalid_argument("initalizing array invalid");
    }
    int x = 0; 
    for (auto i : ar) {
        // turn double into variable
        Variable new_var = Variable();
        new_var.operation = argument;
        new_var.value = i;
        // append
        this->array[x] = new_var; 
        x++;
    }
}

Matrix operator+ (const Matrix a, const Matrix b) {
    // check size of mat
    if (a.width != b.width || a.height != b.height) {
        throw invalid_argument("adding matrix invalid");
    }   
    // do operation
    Matrix return_mat = Matrix(a.width, a.height); 
    for (int x = 0; x < a.height; x++) {
        for (int i = 0; i < a.width; i++) {
            return_mat.array[x*a.height + i] = a.array[x*a.height + i] + b.array[x*a.height + i];
        }
    }
    return return_mat;
}

Matrix operator- (const Matrix a, const Matrix b) {
    // check size of mat
    if (a.width != b.width || a.height != b.height) {
        throw invalid_argument("subtracting matrix invalid");
    }   
    // do operation
    Matrix return_mat = Matrix(a.width, a.height); 
    for (int x = 0; x < a.height; x++) {
        for (int i = 0; i < a.width; i++) {
            return_mat.array[x*a.height + i] = a.array[x*a.height + i] - b.array[x*a.height + i];
        }
    }
    return return_mat;
}

Matrix operator* (const Matrix a, const Matrix b) {
    // check size of mat
    if (a.width != b.width || a.height != b.height) {
        throw invalid_argument("multiplying matrix invalid");
    }   
    // do operation
    Matrix return_mat = Matrix(a.width, a.height); 
    for (int x = 0; x < a.height; x++) {
        for (int i = 0; i < a.width; i++) {
            return_mat.array[x*a.height + i] = a.array[x*a.height + i] * b.array[x*a.height + i];
        }
    }
    return return_mat;
}

Matrix operator/ (const Matrix a, const Matrix b) {
    // check size of mat
    if (a.width != b.width || a.height != b.height) {
        throw invalid_argument("multiplying matrix invalid");
    }   
    // do operation
    Matrix return_mat = Matrix(a.width, a.height); 
    for (int x = 0; x < a.height; x++) {
        for (int i = 0; i < a.width; i++) {
            return_mat.array[x*a.height + i] = a.array[x*a.height + i] / b.array[x*a.height + i];
        }
    }
    return return_mat;
}

template<class T>
T Matrix::operator[] (int x) {
    
}