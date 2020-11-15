#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <vector>
using namespace std;

class Matrix;
class Variable;

class Vector {
public:
    Variable *array;
    int width;
    // Declared in Vec.cpp
    Vector (); 
    Vector (int width);
    // eval / grad.cpp
    Vector eval ();
    Matrix grad ();
    // rest of the functions are declared in operations.cpp
    void operator= (initializer_list<double> ar); 
    void operator= (initializer_list<Variable> ar);
    double& operator[] (int x);
};

// OPERATIONS
Vector operator+ (const Vector &left, const Vector &right);
Vector operator+ (const Vector &left, Vector &right);
Vector operator+ (const Vector &left, const double &right);
Vector operator+ (Vector &left, const Vector &right);
Vector operator+ (Vector &left, Vector &right);
Vector operator+ (Vector &left, const double &right);
Vector operator+ (const double &left, const Vector &right);
Vector operator+ (const double &left, Vector &right);

Vector operator- (const Vector &left, const Vector &right);
Vector operator- (const Vector &left, Vector &right);
Vector operator- (const Vector &left, const double &right);
Vector operator- (Vector &left, const Vector &right);
Vector operator- (Vector &left, Vector &right);
Vector operator- (Vector &left, const double &right);
Vector operator- (const double &left, const Vector &right);
Vector operator- (const double &left, Vector &right);

Vector operator* (const Vector &left, const Vector &right);
Vector operator* (const Vector &left, Vector &right);
Vector operator* (const Vector &left, const double &right);
Vector operator* (Vector &left, const Vector &right);
Vector operator* (Vector &left, Vector &right);
Vector operator* (Vector &left, const double &right);
Vector operator* (const double &left, const Vector &right);
Vector operator* (const double &left, Vector &right);

Vector operator/ (const Vector &left, const Vector &right);
Vector operator/ (const Vector &left, Vector &right);
Vector operator/ (const Vector &left, const double &right);
Vector operator/ (Vector &left, const Vector &right);
Vector operator/ (Vector &left, Vector &right);
Vector operator/ (Vector &left, const double &right);
Vector operator/ (const double &left, const Vector &right);
Vector operator/ (const double &left, Vector &right);
#endif