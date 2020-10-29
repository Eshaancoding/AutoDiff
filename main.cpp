//
//  main.cpp
//  AutoDiff
//
//  Created by Eshaan Arnav on 9/23/20.
//
#include "AutoDiff/AutoDiff.hpp"

int main(int argc, const char * argv[]) {  
    Vector a = Vector(2); 
    Vector b = Vector(2); 
    
    Variable test = Variable();
    Variable x = Variable();
    Variable y = Variable(); 
    a = {x^test, y}; 
    b = {x^y, test};
    Vector result = (a + b).grad({2,3,1});
    cout<<result.array[0].value<<endl;
    cout<<result.array[1].value<<endl;
    cout<<result.array[2].value<<endl;
    cout<<result.width<<endl; 
}
// test id: 5
// x id: 6
// y id: 7

// 2:       7, 5
// total:   5, 6, 7
// map:     0, 1, 2 

// d/dx x ^ 3  + x ^ y = 13
// d/dy y + test = 1
// d/dy x^y + x^test = log(4)