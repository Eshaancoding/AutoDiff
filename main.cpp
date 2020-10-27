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
    a = {x, y};
    cout<<&x<<endl;
    cout<<&a.array[0]<<endl;
    cout<<x.id<<endl;
    cout<<a.array[0].id<<endl; 
}