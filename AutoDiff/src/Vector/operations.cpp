#include "Vector.hpp"

Vector::Vector (int width) {
    this->array = new Variable[width]; 
    this->width = width;
}

void Vector::operator= (initializer_list<double> ar) {
    if (ar.size() != this->width) {
        throw invalid_argument("Vector intialization invalid. Expected " + to_string(this->width) + " inputs not " + to_string(ar.size()));
    }
    for (int i = 0; i < this->width; i++) {
        this->array[i].value = *(ar.begin() + i);  
    }
}

void Vector::operator= (initializer_list<Variable> ar) {
    if (ar.size() != this->width) {
        throw invalid_argument("Vector intialization invalid. Expected " + to_string(this->width) + " inputs not " + to_string(ar.size()));
    }
    for (int i = 0; i < this->width; i++) {
        this->array[i] = *(ar.begin() + i); 
    }
}

Variable Vector::operator[] (int x) {
    return this->array[x]; 
}

Vector::~Vector () {
    delete this->array;       
}

int Vector::return_width () const {
    return this->width;
}

Variable* Vector::return_array () const {
    return this->array;
};

// TIME FOR SOME REAL OPERATIONS
Vector operator+ (const Vector a, const Vector b) {
    Vector return_vec = Vector(a.return_width());
}

Vector operator+ (const Vector a, const double b) {

}

Vector operator+ (const double b, const Vector a) {

}

