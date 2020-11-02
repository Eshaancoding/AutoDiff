#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream> 
#include "Variable.hpp"
#include "Vector.hpp"
using namespace std;

class Matrix {
public: 
    Variable *array;
    int height;
    int width;
    // Declared in Mat.cpp
    Matrix (int width, int height);
    // eval.cpp / grad.cpp
    Matrix eval (vector<double> input);
    Matrix grad (vector<double> input);
    // rest of the functions are declared in operations.cpp
    void operator= (initializer_list<initializer_list<double>> ar);
    void operator= (initializer_list<initializer_list<Variable>> ar);
    Vector operator[] (int x);
}; 

// OPERATIONS 
Matrix operator+ (const Matrix &a, const Matrix &b);
Matrix operator+ (const Matrix &a, const double &b);
Matrix operator+ (const double &b, const Matrix &a);

Matrix operator- (const Matrix &a, const Matrix &b);
Matrix operator- (const Matrix &a, const double &b);
Matrix operator- (const double &b, const Matrix &a);

Matrix operator* (const Matrix &a, const Matrix &b);
Matrix operator* (const Matrix &a, const double &b);
Matrix operator* (const double &b, const Matrix &a);

Matrix operator/ (const Matrix &a, const Matrix &b);
Matrix operator/ (const Matrix &a, const double &b);
Matrix operator/ (const double &b, const Matrix &a);

#endif