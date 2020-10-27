#include "coreMatrix.h"

Matrix Matrix::eval (vector<double> input) {
    Matrix return_mat = Matrix(this->height, this->width);
    for (int i = 0; i < this->height; i++) {
        for (int x = 0; x < this->width; x++) {
            return_mat.array[i * this->height + x].value = this->array[i * this->height + x].eval(input); 
        }
    }
    return return_mat;
}

Matrix Matrix::grad (vector<double> input) {
    // I could create sub-Matrix, which represents matrix for every element, then join them together.
    for (int i = 0; i < this->height; i++) { 
        for (int x = 0; x < this->width; x++) {
            vector<double> grad = this->array[this->height * i + x].grad(input[i]);
        }
    }
}