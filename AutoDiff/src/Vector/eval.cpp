#include "Vector.hpp"

Vector Vector::eval (vector<double> input) {
    Vector new_vec = Vector(this->width);
    for (int i = 0; i < this->width; i++) {
        new_vec.array[i].value = this->array[i].eval({input});
    }
    return new_vec;
}