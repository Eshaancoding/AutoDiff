#include "coreMatrix.h"

Matrix::Matrix (const int height, const int width) {
    this->height = height;
    this->width = width;
    this->array = new Variable[this->height * this->width];
}

void Matrix::operator= (initializer_list<initializer_list<Variable>> ar) {
    if (ar.size() != this->height) {
        throw invalid_argument("initialzing is invalid: Expected height is " + to_string(this->height) + " , Recieved height is: " + to_string(ar.size()));
    }
    if (ar.begin()->size() != this->width) {
        throw invalid_argument("initialzing is invalid: Expected width is " + to_string(this->width) + " , Recieved width is: " + to_string(ar[0].size()));
    }
    
}

void Matrix::operator= (initializer_list<initializer_list<double>> ar) {
    
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