#include "Variable.hpp"
#include <iostream>
#include <vector>
using namespace std;

class Vector {
private:
    Variable *array;
    int width;
public:
    // Init declared in operations.cpp
    Vector (int width); 
    void operator= (initializer_list<double> ar); 
    void operator= (initializer_list<Variable> ar);
    Vector eval (vector<double> input);
    Vector grad (vector<double> input);
    Variable operator[] (int x);
    ~Vector ();
    int return_width () const;
    Variable* return_array () const;
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
