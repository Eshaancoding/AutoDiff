#include "Vector.hpp"
#include "Variable.hpp"

Vector operator+ (const Vector &left, const Vector &right) {
    if (left.width != right.width) throw invalid_argument("Width is not compatable."); 
    Vector new_vec = Vector(left.width);
    for (int i = 0; i < left.width; i++) {
        Vector *l = new Vector(right.width);
        Vector *r = new Vector(left.width); 
        *l = left;
        *r = right;
        new_vec.array[i] = l->array[i] + r->array[i]; 
    }
    return new_vec;
}

Vector operator+ (const Vector &left, Vector &right) {
    
}

Vector operator+ (const Vector &left, const double &right) {

}

Vector operator+ (Vector &left, const Vector &right) {

}

Vector operator+ (Vector &left, Vector &right) {

}

Vector operator+ (Vector &left, const double &right) {

}

Vector operator+ (const double &left, const Vector &right) {

}

Vector operator+ (const double &left, Vector &right) {

}