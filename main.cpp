//
//  main.cpp
//  AutoDiff
//
//  Created by Eshaan Arnav on 9/23/20.
//
#include "AutoDiff/AutoDiff.h"

int main(int argc, const char * argv[]) {  
    Variable h = Variable();
    Variable s = Variable(); 
    Variable a = Variable();
    Matrix x(1,2);
    x = {
        h^s,h^a,
    };
    Matrix result = x.grad({2,3,4});
}
