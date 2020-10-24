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