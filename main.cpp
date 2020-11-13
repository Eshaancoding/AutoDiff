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
    Variable x = Variable(1); 
    Variable y = Variable(6);
    Variable g = Variable(8);
    Variable z = g.clip(5, y); 
    cout<<z.eval()<<endl; 
}

// x = 3
// y = 1
// z = 2
// x^y + z + x
// df_1 / dx = 2
// 3 ^ 1 * log(3)