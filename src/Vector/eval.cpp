#include "Vector.hpp"
#include "Variable.hpp"

Vector Vector::eval () {
    Vector new_vec = Vector(this->width);
    for (int i = 0; i < this->width; i++) {
        new_vec.array[i].value = this->array[i].eval();
        new_vec.array[i].operation = op::argument;
    }
    return new_vec;
}