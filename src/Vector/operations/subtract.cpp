#include "Vector.hpp"
#include "Variable.hpp"

Vector operator- (const Vector &left, const Vector &right) {
    if (left.width != right.width) throw invalid_argument("Width is not compatable."); 
    Vector new_vec = Vector(left.width);
    for (int i = 0; i < left.width; i++) {
        Vector *l = new Vector(right.width);
        Vector *r = new Vector(left.width); 
        *l = left;
        *r = right;
        new_vec.array[i] = l->array[i] - r->array[i]; 
    }
    return new_vec;
}

Vector operator- (const Vector &left, Vector &right) {
    if (left.width != right.width) throw invalid_argument("Width is not compatable."); 
    Vector new_vec = Vector(left.width);
    for (int i = 0; i < left.width; i++) {
        Vector *l = new Vector(right.width);
        *l = left;
        new_vec.array[i] = l->array[i] - right.array[i]; 
    }
    return new_vec;
}

Vector operator- (const Vector &left, const double &right) {
    Vector new_vec = Vector(left.width);
    for (int i = 0; i < left.width; i++) {
        Vector *l = new Vector(left.width);
        *l = left;
        new_vec.array[i] = l->array[i] - right; 
    }
    return new_vec;
}

Vector operator- (Vector &left, const Vector &right) {
    if (left.width != right.width) throw invalid_argument("Width is not compatable."); 
    Vector new_vec = Vector(left.width);
    for (int i = 0; i < left.width; i++) {
        Vector *r = new Vector(right.width);
        *r = right;
        new_vec.array[i] = left.array[i] - r->array[i]; 
    }
    return new_vec;   
}

Vector operator- (Vector &left, Vector &right) {
    if (left.width != right.width) throw invalid_argument("Width is not compatable."); 
    Vector new_vec = Vector(left.width);
    for (int i = 0; i < left.width; i++) {
        new_vec.array[i] = left.array[i] - right.array[i]; 
    }
    return new_vec;
}

Vector operator- (Vector &left, const double &right) {
    Vector new_vec = Vector(left.width);
    for (int i = 0; i < left.width; i++) {
        new_vec.array[i] = left.array[i] - right;
    }
    return new_vec;
}

Vector operator- (const double &left, const Vector &right) {
    Vector new_vec = Vector(right.width);
    for (int i = 0; i < right.width; i++) {
        Vector *r = new Vector(right.width);
        *r = right;
        new_vec.array[i] = left - r->array[i]; 
    }
    return new_vec;
}

Vector operator- (const double &left, Vector &right) {
    Vector new_vec = Vector(right.width);
    for (int i = 0; i < right.width; i++) {
        new_vec.array[i] = left - right.array[i]; 
    }
    return new_vec;
}