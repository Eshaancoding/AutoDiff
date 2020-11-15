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
    Vector a = Vector(2); 
    a = {6,32}; 
    Vector b = Vector(2); 
    b = {3,5};
    Vector c = Vector(2);
    c = {2,8};
    Vector result = ((a + b) + (a + b)).eval();
    cout<<result[0]<<endl;
    cout<<result[1]<<endl;
}

// x = 3
// y = 1
// z = 2
// x^y + z + x
// df_1 / dx = 2
// 3 ^ 1 * log(3)