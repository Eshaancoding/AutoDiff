#include "Vector.hpp"
#include "Variable.hpp"

void Vector::operator= (initializer_list<double> ar) {
    for (int i = 0; i < ar.size(); i++) {
        this->array[i].value = *(ar.begin() + i);
    }
} 

void Vector::operator= (initializer_list<Variable> ar) {
    for (int i = 0; i < ar.size(); i++) {
        this->array[i] = *(ar.begin() + i);
    }
}

double& Vector::operator[] (int x) {
    return this->array[x].value;
}