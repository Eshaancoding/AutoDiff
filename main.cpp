//
//  main.cpp
//  AutoDiff
//
//  Created by Eshaan Arnav on 9/23/20.
//
#include "AutoDiff.hpp"
#include <iostream>
using namespace std;

int main () {
    Variable x = Variable(); // id: 1
    Variable y = Variable(); // id: 2
    Variable z = Variable(); // id: 3
    Vector a = Vector(2);
    Vector b = Vector(2);
    // assign vector
    a = {x^y, z}; 
    b = {z + x, y};
    Matrix result = (a + b).grad({3,1,2});
    result.print();
}

// x = 3
// y = 1
// z = 2
// x^y + z + x
// df_1 / dx = 2
// 3 ^ 1 * log(3)