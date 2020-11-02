#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "Variable.hpp"
#include <iostream>
#include <vector>
using namespace std;

class Vector {
public:
    Variable *array;
    int width;
    // Declared in Vec.cpp
    Vector (int width); 
    // eval / grad.cpp
    Vector eval (vector<double> input);
    Vector grad (vector<double> input);
    // rest of the functions are declared in operations.cpp
    void operator= (initializer_list<double> ar); 
    void operator= (initializer_list<Variable> ar);
    double operator[] (int x);
};

// OPERATIONS
Vector operator+ (const Vector &a, const Vector &b);
Vector operator+ (const Vector &a, const double &b);
Vector operator+ (const double &b, const Vector &a);

Vector operator- (const Vector &a, const Vector &b);
Vector operator- (const Vector &a, const double &b);
Vector operator- (const double &b, const Vector &a);

Vector operator* (const Vector &a, const Vector &b);
Vector operator* (const Vector &a, const double &b);
Vector operator* (const double &b, const Vector &a);

Vector operator/ (const Vector &a, const Vector &b);
Vector operator/ (const Vector &a, const double &b);
Vector operator/ (const double &b, const Vector &a);
#endif