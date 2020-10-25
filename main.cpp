//
//  main.cpp
//  AutoDiff
//
//  Created by Eshaan Arnav on 9/23/20.
//
#include "AutoDiff/AutoDiff.h"

int main(int argc, const char * argv[]) {
    Matrix x(2,2);
    x = {
        2,2,
        4,6
    };
    Matrix y(2,2);
    y = {
        6,4,
        7,2
    };
    Matrix z = x + y;
    cout<<z.eval({}).array[0].value<<endl;
}
