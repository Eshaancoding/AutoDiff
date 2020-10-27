//
//  main.cpp
//  AutoDiff
//
//  Created by Eshaan Arnav on 9/23/20.
//
#include "AutoDiff/AutoDiff.hpp"

int main(int argc, const char * argv[]) {  
    Vector a = Vector(2); 
    Variable x = Variable();
    Variable y = Variable(); 
    a = {x,x};
    Vector b = Vector(2);
    b = {3,4};
    Vector result = a + b;
    // check
    cout<<result.array[0].child[0]->operation<<endl; // input
    cout<<result.array[1].child[0]->operation<<endl; // input
    cout<<result.array[0].child[1]->operation<<endl; 
    cout<<result.array[1].child[1]->operation<<endl;
}