//
//  main.cpp
//  AutoDiff
//
//  Created by Eshaan Arnav on 9/23/20.
//
#include "AutoDiff/AutoDiff.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    Matrix x(2,2);
    x = {
        2,3,
        4,6
    };
    Variable j;
    Variable y; 
    Variable z;
    Variable h;
    cout<<x.array[0].value<<endl;
    cout<<x.array[1].value<<endl;
    cout<<x.array[2].value<<endl;
    cout<<x.array[3].value<<endl;
}
