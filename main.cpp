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
    Variable x = Variable();
    Variable y = Variable();
    Variable z = Variable();
    Vector a = Vector(2);
    Vector b = Vector(2);
    // assign vector
    a = {x^y, z}; 
    b = {z + x, y};
    Matrix result = (a + b).grad({3,1,2});
    result.print();
    // test
    Variable res = x^y + z + x;
    cout<<res.grad({3,1,2})[1]<<endl; 
}

// x = 3
// y = 1
// z = 2
// x^y + z + x
// df_1 / dx = 2