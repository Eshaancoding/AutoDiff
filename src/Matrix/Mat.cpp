#include "Matrix.hpp"
#include "Vector.hpp"
#include "Variable.hpp"

Matrix::Matrix (int height, int width) {
    this->width = width;
    this->height = height;
    array = new Vector[height];
    for (int i = 0; i < height; i++) {
        array[i] = Vector(width);
    }
}

void Matrix::print () {
    cout<<endl;
    for (int i = 0; i < this->height; i++) {
        for (int x = 0; x < this->width; x++) {
            cout<<this->array[i].array[x].value<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
