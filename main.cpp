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
    Vector result = (a + b).eval({2,3,1});
    cout<<result[0].value<<endl;
    cout<<result[1].value<<endl;
    cout<<result[2].value<<endl;
    cout<<result.width<<endl; 
}
