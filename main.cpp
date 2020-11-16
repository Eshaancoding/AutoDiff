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
    Matrix result = (3 * (a * a * a)).grad();
    result.print(); 
}
// 3x^3
// 9x^2
// 9(6)^2
// 9 (36)
// 