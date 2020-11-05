#include "Matrix.hpp"
#include "Vector.hpp"

Matrix::Matrix (int height, int width) {
    array = new Vector[height];
    for (int i = 0; i < height; i++) {
        array[i] = Vector(width);
    }
}
