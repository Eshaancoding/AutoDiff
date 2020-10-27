#include "Vector.hpp"

// Helper func
Vector copy_contents_vec (const Vector &l) {
    Vector new_vec = Vector(l.width);
    new_vec.array = l.array;
    new_vec.width = l.width;
    return new_vec;
}

// *****************************************************************
// *              equal two / subscript operator                   *
// *****************************************************************


void Vector::operator= (initializer_list<double> ar) {
    if (ar.size() != this->width) {
        throw invalid_argument("Vector intialization invalid. Expected " + to_string(this->width) + " inputs not " + to_string(ar.size()));
    }
    for (int i = 0; i < this->width; i++) {
        this->array[i].value = *(ar.begin() + i);  
        this->array[i].operation = op::argument;
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

// *****************************************************************
// *                         ADDING                                *
// *****************************************************************

Vector operator+ (const Vector &a, const Vector &b) {
    // check size
    if (a.width != b.width) {
        throw invalid_argument("Adding vectors invalid");
    }
    // make copy
    Vector new_a = copy_contents_vec(a);
    Vector new_b = copy_contents_vec(b);
    // do operations
    Vector new_vec = Vector(a.width);
    for (int i = 0; i < new_vec.width; i++) {
        new_vec.array[i] = new_a[i] + new_b[i];
    }
    return new_vec;
}

Vector operator+ (const Vector &a, const double &b) {
    // make copy
    Vector new_a = copy_contents_vec(a);
    // do operations
    Vector new_vec = Vector(a.width);
    for (int i = 0; i < new_vec.width; i++) {
        new_vec.array[i] = new_a[i] + b;
    }
    return new_vec;
}

Vector operator+ (const double &b, const Vector &a) {
    // make copy
    Vector new_a = copy_contents_vec(a);
    // do operations
    Vector new_vec = Vector(a.width);
    for (int i = 0; i < new_vec.width; i++) {
        new_vec.array[i] = b + new_a[i];
    }
    return new_vec;
}